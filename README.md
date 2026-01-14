# 🧮 Project: Math Quiz Game

> **"Building an intelligent engine to generate arithmetic problems and test mental agility."** 🧠

📌 This project is the second practical application within **[Level 05: Algorithms & Problem-Solving Level 2](https://github.com/ammmrrr18-cloud/Programming-Foundations-Roadmap/tree/main/05%20-%20Algorithms%20%26%20Problem-Solving%20%E2%80%93%20Level%202)**. The project focuses on building a dynamic "Question Engine" that handles various difficulty levels and mathematical operations.

---

## 🎯 About the Project
The program is an interactive mathematical challenge where the user specifies the number of questions, difficulty level, and operation type. The system generates random questions, validates answers instantly, and provides visual feedback by changing the console screen color.

---

## 🛠️ Technical Highlights
Advanced programming concepts were implemented to ensure code flexibility and robustness:

* **Dynamic Level System:** Supports (Easy, Med, Hard) and a **Mix** level that randomly selects the difficulty for each question using **Recursion**.
* **Operation Engine:** Supports Addition, Subtraction, Multiplication, and Division, including a **Mix** option to vary the operation type per question.
* **Structured Data Management:** Heavily relies on **`Structs`** to pass data between functions (e.g., `stPartsOfQuestion` and `stFinalGameResults`).
* **User Experience (UI/UX):** * Changes screen color to **Green** on correct answers.
    * Changes screen color to **Red** with an audible alert `\a` on incorrect answers.

---

## 🕹️ How to Play
1.  **Set Quantity:** Choose how many questions you want to solve.
2.  **Select Difficulty:** Choose between [1] Easy, [2] Med, [3] Hard, or [4] Mix.
3.  **Choose Operation:** Select [1] Add, [2] Sub, [3] Mul, [4] Div, or [5] Mix.
4.  **Solve:** Start answering the problems as they appear.
5.  **Results:** At the end, you will receive a comprehensive report showing your correct/wrong answers and your final status (Won/Fail).

---

## 📂 Level 05 Projects
You can also view the other project associated with this level:
* **🚀 [Stone-Paper-Scissors Game](https://github.com/ammmrrr18-cloud/Project-1-Stone---Paper---Scissor)**: A practical application of **Probabilistic Logic** and game loops.

---

## 🚀 Learning Outcomes
Through this project, I have enhanced my skills in:
- ✅ **Logic Flow Management:** Handling complex conditional paths and program states.
- ✅ **Professional Randomization:** Using time-based seeding and controlled ranges to create non-repetitive content.
- ✅ **Clean Code Principles:** Decomposing the system into small, highly efficient, and single-responsibility functions.

---
*📌 "Mathematics is the language of the universe; Programming is the tool we use to speak it."*
