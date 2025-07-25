# 🏥 Hospital Management System (C++)

A comprehensive, menu-driven **Hospital Management System** built in C++ for console. This project provides functionalities for managing patients, doctors, and appointments, including **adding**, **viewing**, **editing**, and **deleting** records, as well as **login/signup** features for basic user authentication.

## 📌 Key Features

- 🔐 **User Signup/Login system** (credentials stored in a file)
- 🧑‍⚕️ Add, View, Edit, and Delete **Doctor Records**
- 🧑‍🤝‍🧑 Add, View, Edit, and Delete **Patient Records**
- 📅 **Appointment Booking System**
- 🗃️ All data is stored and retrieved from `.txt` files (no database used)
- 📄 Cleanly structured code using functions and file handling

## 🛠 Technologies Used

- **C++** (Standard I/O, file handling, vectors)
- **Header Files**: `<iostream>`, `<fstream>`, `<conio.h>`, `<vector>`
- **Platform**: Windows (due to usage of `system("cls")` and `<conio.h>`)

## 📂 File Structure

├── Patients.txt # Stores patient records
├── Doctor.txt # Stores doctor records
├── Appointment.txt # Stores appointment records
├── SignUp.txt # Stores login credentials


## 🔑 Login System

- Users can **Sign Up** and **Login**.
- Login credentials (username and 8-character password) are saved to `SignUp.txt`.
- Password input is masked with `*` using `getch()`.

## 🗂 Functional Modules

| Functionality         | Description                                        |
|-----------------------|----------------------------------------------------|
| Add Patient/Doctor    | Inputs name, disease/speciality, blood group, etc.|
| View Records          | Displays stored records from text files           |
| Delete Record         | Removes a selected record by number               |
| Edit Record           | Updates name, disease/speciality, or blood info   |
| Book Appointment      | Collects patient, doctor, date, and time          |

## 🔄 Future Enhancements

- Replace file-based storage with a database (e.g., SQLite or MySQL)
- Add GUI (using Qt, SFML, or Windows Forms)
- Add role-based access control (Admin, Doctor, Patient)
- Implement data validation and encryption for security

## 👨‍💻 Author

- **Developer:** [Muhammad Uneeb Khan]
- **Language:** C++
- **Platform:** Windows Console


Feel free to explore, modify, and build upon this code for your learning or academic use.

