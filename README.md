# 🗳️ C Voting System

Welcome to a **simple yet powerful terminal-based voting system** built in C!  
This project simulates a complete voting workflow including **voter registration**, **candidate registration**, **secure voting**, and **vote visualization**.

---

## 🚀 Features

✨ Admin & Voter portals  
🔒 Prevents double voting  
📊 Vote bar chart visualization  
📁 File-based data storage (no database needed)  
🧩 Modular and easy to expand

---

## 🔐 Admin Access

| Action         | Code       |
|----------------|------------|
| Admin Login    | `nname`    |
| Exit Portal    | `exitnn`   |

---

## 🧭 Navigation

### 🛠️ Compile

```bash
gcc voting_system.c -o voting_system
▶️ Run
bash
Copy
Edit
./voting_system
🗃️ File Structure

📄 File Name	📌 Purpose
voterReg.txt	Stores registered voter details
CandidateReg.txt	Contains candidate info (name, ID, position, votes)
CandidateVotes.txt	Stores vote count for each candidate
votedAlready.txt	Tracks who has already voted
👩‍⚖️ Admin Portal
🔹 Register voters by name and ID
🔹 Register candidates with position
🔹 View vote counts as a text-based graph (bar chart)
🔹 Admin code required for access
🔹 Exit portal with special code

🗳️ Voter Portal
✅ Login using your voter ID
✅ Vote for candidates in each position
❌ Prevents double voting (tracks voter IDs)
📥 All data stored safely in .txt files

📊 Sample Voting Results
nginx
Copy
Edit
John Doe     | ########## 10
Jane Smith   | #######    7
Each # represents one vote. Clean and visual, even in a terminal window!

📌 Limitations
⚠️ No encryption or password protection
⚠️ Data stored in plain text files
⚠️ Terminal-only interface (CLI-based)
⚠️ Basic input validation

🌱 Future Enhancements
🚀 Password-protected voter/admin logins
🗄️ Database integration (SQLite, PostgreSQL)
🖥️ GUI or web frontend (React, GTK, Qt, etc.)
🧾 Vote timestamps + audit logs for accountability
📈 Real-time vote visualization

📜 License
This project is open source under the MIT License.
Feel free to fork it, star it ⭐, and build something amazing on top of it!

✍️ Author
Made by Jabulani Kapherachoka
Let’s connect: GitHub
