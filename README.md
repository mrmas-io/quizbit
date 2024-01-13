<h1 style="text-align:center;font-family:Roboto,serif;">Quizbit - Quiz Game 🎮</h1>

<p style="text-align:center;"><img src="https://socialify.git.ci/mrmas-io/quizbit/image?description=1&amp;font=Inter&amp;forks=1&amp;issues=1&amp;language=1&amp;name=1&amp;owner=1&amp;pattern=Floating%20Cogs&amp;pulls=1&amp;stargazers=1&amp;theme=Auto" alt="project-image"></p>

<h2 style="font-family:Lucida Console,serif;">📝 Project Description</h2>
<p  style="font-family:DejaVu Sans Mono,serif;">This project is a simple &amp; fun Terminal based Quiz Game written in C. The game tests your knowledge in three categories: Science Sports and General Knowledge. To participate users can either log in or sign up to their account. Account information's are stored in an SQLite database file. In addition to tracking user information the game also maintains a record of each player's scores.</p>


<h2 style="font-family:Lucida Console,serif;">🧐 Features</h2>
<h3 style="font-family:DejaVu Sans Mono,serif;"> The Quiz Game is user-friendly and offers the following features:</h3>
<ul style="font-family:DejaVu Sans Mono,serif;">
   <li><strong>Sign Up:</strong> New users can create an account with a unique username and password.</li>
   <li><strong>Log In:</strong> Registered users can log in with their credentials.</li>
   <li><strong>Quiz Category:</strong> Select from Science Sports or General Knowledge quizzes.</li>
   <li><strong>Answer Questions:</strong> The game will present random questions from the chosen category.</li>
   <li><strong>Score Tracking:</strong> Your scores are recorded and can be viewed in your profile.</li>
   <li><strong>Account Management:</strong> You can view your profile edit and delete your profile.</li>
</ul>

<h2 style="font-family:Lucida Console,serif;">🛠️ Installation Steps:</h2>
``REQUIREMENTS: OpenSSL, SQLite3, GCC, & Git.``

<p style="font-family:DejaVu Sans Mono,serif;">1. Clone The Repo</p>

```bash
git clone https://github.com/mrmas-io/quizbit.git
```

<p style="font-family:DejaVu Sans Mono,serif;">2. Build The Project</p>

```bash
make
```

<p style="font-family:DejaVu Sans Mono,serif;">3. Run The Project</p>

```bash
make run
```

<p style="font-family:DejaVu Sans Mono,serif;">4. Clean The Build Files</p>

```bash
make clean
```
``NOTE: running make clean may prompt you to remove the generated .db files``

<h2 style="font-family:Lucida Console,serif;">Usage Guide</h2>
<p style="font-family:DejaVu Sans Mono,serif;"><code>Follow the on-screen instructions to create an account, log in, and enjoy the quiz.</code></p>

<ol style="font-family:DejaVu Sans Mono,serif">
   <li>Run the application.</li>
   <li>Choose &quot;Sign Up&quot; and follow the prompts to create an account.</li>
   <li>Log in with your newly created account.</li>
   <li>Select a quiz category.</li>
   <li>Answer the quiz questions and track your score.</li>
</ol>

<h2 style="font-family:Lucida Console,serif;">🍰 Contribution Guidelines:</h2>
<p style="font-family:DejaVu Sans Mono,serif;">If you&#39;d like to contribute, please follow these steps</p>

<ul style="font-family:DejaVu Sans Mono,serif;">
   <li>Fork the repository.</li>
   <li>Create a new branch for your feature or bug fix.</li>
   <li>Make your changes and ensure all tests pass.</li>
   <li>Submit a pull request.</li>
   <li>Your contribution will be reviewed and merged.</li>
</ul>

<h2 style="font-family:Lucida Console,serif;">💻 Data Storage</h2>
<p style="font-family:DejaVu Sans Mono,serif;">The project uses a sqlite3 database to store &amp; retrieve user/player information and the quiz question &amp; answer information.</p>

<h2 style="font-family:Lucida Console,serif;">🛡️ License:</h2>
<p style="font-family:DejaVu Sans Mono,serif;">This project is licensed under the <a href="LICENSE">MIT License</a>. You are free to use modify and distribute this software in accordance with the terms of the license.</p>
