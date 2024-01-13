<div>
<style>
    h1 {
        font-family: "Roboto", "Helvetica Neue", Arial, sans-serif;
    }
    h2 {
        color: white;
        font-size: 30px;
        font-family: "Lucida Console", "Courier New", monospace;
    }
    h3 {
        color: white;
        font-size: 20px;
        font-family: "Lucida Console", "Courier New", monospace;
    }
    p, li {
        font-family: "DejaVu Sans Mono", serif;
    }
</style>
</div>

<h1 align="center" id="title"> Quizbit - Quiz Game 🎮</h1>

<p align="center"><img src="https://socialify.git.ci/mrmas-io/quizbit/image?description=1&amp;font=Inter&amp;forks=1&amp;issues=1&amp;language=1&amp;name=1&amp;owner=1&amp;pattern=Floating%20Cogs&amp;pulls=1&amp;stargazers=1&amp;theme=Auto" alt="project-image"></p>

<h2>📝 Project Description</h2>
<p id="description">This project is a simple &amp; fun Terminal based Quiz Game written in C. The game tests your knowledge in three categories: Science Sports and General Knowledge. To participate users can either log in or sign up to their account. Account information's are stored in an SQLite database file. In addition to tracking user information the game also maintains a record of each player's scores.</p>

<h2>🧐 Features</h2>
### The Quiz Game is user-friendly and offers the following features:

*   **Sign Up:** New users can create an account with a unique username and password.
*   **Log In:** Registered users can log in with their credentials.
*   **Quiz Category:** Select from Science Sports or General Knowledge quizzes.
*   **Answer Questions:** The game will present random questions from the chosen category.
*   **Score Tracking:** Your scores are recorded and can be viewed in your profile.
*   **Account Management:** You can view your profile edit and delete your profile.

<h2>🛠️ Installation Steps:</h2>
``REQUIREMENTS: OpenSSL, SQLite3, GCC, & Git.``
<p>1. Clone The Repo</p>

```bash
git clone https://github.com/mrmas-io/quizbit.git
```

<p>2. Build The Project</p>

```bash
make
```

<p>3. Run The Project</p>

```bash
make run
```

<p>4. Clean The Build Files</p>

```bash
make clean
```
``NOTE: running make clean may prompt you to remove the generated .db files``

<h2>📝 Usage Guide</h2>
``Follow the on-screen instructions to create an account, log in, and enjoy the quiz.``
1. Run the application.
2. Choose "Sign Up" and follow the prompts to create an account.
3. Log in with your newly created account.
4. Select a quiz category.
5. Answer the quiz questions and track your score.

<h2>🍰 Contribution Guidelines:</h2>

If you'd like to contribute, please follow these steps
- Fork the repository.
- Create a new branch for your feature or bug fix.
- Make your changes and ensure all tests pass.
- Submit a pull request.
- Your contribution will be reviewed and merged.

<h2>💻 Data Storage</h2>

The project uses a sqlite3 database to store & retrieve user/player information and the quiz question & answer information.


<h2>🛡️ License:</h2>

This project is licensed under the [MIT License](LICENSE). You are free to use modify and distribute this software in accordance with the terms of the license.