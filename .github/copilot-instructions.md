# Copilot / AI Agent Instructions — firstproject (workspace-aware)

Purpose: Help an AI coding agent be immediately productive across this workspace. This repository (`firstproject`) is small and contains simple C++ exercises, but the workspace also contains a larger project `InPactAI/` (FastAPI backend + React frontends). This file focuses on actionable, discoverable patterns and examples the agent can use.

- Quick context: `firstproject/` contains small C++ practice files (`problem1.cpp`, `problem2.cpp`). The larger app is in `InPactAI/` and uses FastAPI (backend) and Vite/React (frontend). Use examples from both when relevant.

- Where to work:
  - Primary repository for this instruction file: `firstproject/` (this file lives at `.github/copilot-instructions.md`).
  - For full-stack work reference `InPactAI/` subfolders: `InPactAI/Backend/`, `InPactAI/Frontend/`, and `InPactAI/LandingPage/`.

- Build & run commands (discoverable from repo files):
  - Backend (FastAPI):
    - Install: `cd InPactAI/Backend && pip install -r requirements.txt`
    - Dev server: `cd InPactAI/Backend/app && uvicorn main:app --reload --host 0.0.0.0 --port 8000`
    - Alternate (docker): `cd InPactAI/Backend && docker-compose up --build`
  - Frontend (Vite/React):
    - `cd InPactAI/Frontend && npm install`
    - `npm run dev` to start local dev server (usually served at `http://localhost:5173`).
  - C++ exercises (firstproject):
    - Compile: `g++ problem2.cpp -o problem2` then `./problem2` (or use your platform's C++ toolchain).

- Environment & secrets:
  - Many components use a `.env` (see `InPactAI/Frontend/.env-example` and backend `.env-example`). Backend loads env variables with `dotenv.load_dotenv()` (see `InPactAI/Backend/app/main.py`).
  - Database connection strings are stored in env and referenced in `InPactAI/Backend/app/db` files; seed scripts are in `app/db/seed.py`.

- Architectural highlights you should reference when modifying backend code:
  - FastAPI app uses a `lifespan` async context manager (`app = FastAPI(lifespan=lifespan)`) to run startup tasks like table creation and database seeding (see `InPactAI/Backend/app/main.py`). Keep startup logic idempotent.
  - Database: async SQLAlchemy engine pattern. Example:
    - `async with engine.begin() as conn: await conn.run_sync(models.Base.metadata.create_all)` — use `run_sync` for sync metadata operations inside async context.
    - Seed data is executed after tables creation (`seed_db()`).
  - Routing: routers are created in `app/routes/*` and added with `app.include_router(...)`. When adding new endpoints, put them into an appropriate `routes` module and register in `main.py`.
  - CORS: configured to allow `http://localhost:5173` (the frontend dev host). If adding new dev ports, update `CORSMiddleware` accordingly.

- Code patterns & conventions to follow (observable rules):
  - Python backend favors async endpoints and async DB access. Prefer async functions and await DB calls.
  - Keep DB setup idempotent and safe to run on repeated restarts (use `create_all` and seed only if necessary).
  - Files that demonstrate important patterns:
    - `InPactAI/Backend/app/main.py` — startup, CORS, router registration, lifespan handling.
    - `InPactAI/Backend/app/db/seed.py` — how seed data is inserted.
    - `InPactAI/Frontend/` — Vite + React structure; dev server runs on 5173.
    - `firstproject/problem*.cpp` — single-file small examples (compile & run locally).

- PR & code-change guidance for the agent:
  - Make minimal, focused changes. If modifying `main.py` startup logic, ensure it remains idempotent and that table creation and seeding are safe.
  - Add a brief note in the PR body about the files changed and why (e.g., `Update router registration to include new ai route; preserves existing lifespan behavior`).

- Debugging tips (from discoverable scripts):
  - Backend errors often show in uvicorn logs. Reproduce by starting `uvicorn` in `InPactAI/Backend/app` and reading stack traces.
  - If DB migrations or table creation fail, check generated SQL and connection string in env; seed errors usually log exceptions in `seed_db()` calls.

- Examples to copy/paste when asked to run or test locally:
  - Start backend dev server (Windows PowerShell):

    cd .\InPactAI\Backend\app; uvicorn main:app --reload --host 0.0.0.0 --port 8000

  - Start frontend dev server (Windows PowerShell):

    cd .\InPactAI\Frontend; npm install; npm run dev

  - Compile and run a C++ exercise:

    g++ .\firstproject\problem2.cpp -o .\firstproject\problem2.exe; .\firstproject\problem2.exe

- When in doubt, inspect these files first (they frequently contain the project conventions referenced above):
  - `InPactAI/Backend/app/main.py`
  - `InPactAI/Backend/requirements.txt`
  - `InPactAI/Frontend/package.json` and `.env-example`
  - `firstproject/README.md` and `firstproject/problem2.cpp`

- What not to assume:
  - There are no standardized unit tests present. Do not assume a test harness exists unless you find it.
  - Do not modify production database connection strings — use `.env` and local dev placeholders.

If anything here is unclear or you want the agent to adopt stricter rules (commit message style, branching rules, more test scaffolding), tell me which parts to expand or enforce and I will iterate the instructions.
