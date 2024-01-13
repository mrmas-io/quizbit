<h1 align="center" id="title">Quizbit - Quiz Game 🎮</h1>

<p align="center"><img src="https://socialify.git.ci/mrmas-io/quizbit/image?description=1&amp;font=Inter&amp;forks=1&amp;issues=1&amp;language=1&amp;name=1&amp;owner=1&amp;pattern=Floating%20Cogs&amp;pulls=1&amp;stargazers=1&amp;theme=Auto" alt="project-image"></p>

## 📝 Project Description
This project is a simple &amp; fun Terminal based Quiz Game written in C. The game tests your knowledge in three categories: Science Sports and General Knowledge. To participate users can either log in or sign up to their account. Account information's are stored in an SQLite database file. In addition to tracking user information the game also maintains a record of each player's scores.


## 🧐 Features
### The Quiz Game is user-friendly and offers the following features:
- **Sign Up:** New users can create an account with a unique username and password.
- **Log In:** Registered users can log in with their credentials.
- **Quiz Category:** Select from Science Sports or General Knowledge quizzes.
- **Answer Questions:** The game will present random questions from the chosen category.
- **Score Tracking:** Your scores are recorded and can be viewed in your profile.
- **Account Management:** You can view your profile edit and delete your profile.

## 🛠️ Installation Steps:
``REQUIREMENTS: OpenSSL, SQLite3, GCC, & Git.``

1. Clone The Repo
   ```bash
   git clone https://github.com/mrmas-io/quizbit.git
   ```

2. Build The Project
   ```bash
   make
   ```

3. Run The Project
   ```bash
   make run
   ```

4. Clean The Build Files
   ```bash
   make clean
   ```
``NOTE: running make clean may prompt you to remove the generated .db files``

## Usage Guide
``Follow the on-screen instructions to create an account, log in, and enjoy the quiz.``

- Run the application.
- Choose &quot;Sign Up&quot; and follow the prompts to create an account.
- Log in with your newly created account.
- Select a quiz category.
- Answer the quiz questions and track your score.

## 🍰 Contribution Guidelines:
If you&#39;d like to contribute, please follow these steps

- Fork the repository.
- Create a new branch for your feature or bug fix.
- Make your changes and ensure all tests pass.
- Submit a pull request.
- Your contribution will be reviewed and merged.

## 💻 Data Storage
The project uses a sqlite3 database to store &amp; retrieve user/player information and the quiz question &amp; answer information.

## 🛡️ License:
This project is licensed under the [MIT License](LICENSE). You are free to use modify and distribute this software in accordance with the terms of the license.
