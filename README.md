# 🏥 Dual-Purpose Management System  

A Linux-based management system designed to streamline operations in **doctor cabinets**.  
Built in **C** on **Ubuntu**, it provides two dedicated interfaces — one for **medical staff** and another for **patients** — allowing for efficient appointment scheduling, record management, and personal data handling.

---

## 🚀 Key Features  

- Manage and update patient records  
- Schedule, modify, and cancel appointments  
- Distinct **Admin** and **Patient** modes  
- Text-based interface (CLI) for simplicity and performance  
- Modular and maintainable **C architecture**

---

## 🧩 Technologies Used  

- **Language:** C  
- **Platform:** Linux / Ubuntu  
- **Build System:** Makefile  

---

## 📁 Project Structure  

```plaintext
dual-purpose-management-system/
├── src/
│   ├── main.c
│   ├── cabinet.c
│   ├── cabinet.h
│   ├── menu.c
│   └── menu.h
├── docs/
│   └── Menu_Showcase.png
├── Makefile
├── README.md
└── LICENSE
```

---

## ⚙️ How to Build & Run  

### 1️⃣ Clone the Repository  
```bash
git clone https://github.com/yourusername/dual-purpose-management-system.git
cd dual-purpose-management-system
```

### 2️⃣ Compile  
```bash
make
```

### 3️⃣ Run  
```bash
./dpms
```

### 🧹 Clean Build Files  
```bash
make clean
```

---

## 🖼️ Interface Preview  

<p align="center">
  <img src="docs/Menu_Showcase.PNG" width="420" alt="System Menu Preview"/>
</p>

---

## 🧠 Code Overview  

| File | Description |
|------|--------------|
| **main.c** | Entry point of the program — manages initialization and main menu logic. |
| **cabinet.c / .h** | Handles patient data, record storage, appointment logic, and feedback system. |
| **menu.c / .h** | Defines user interaction menus for both Admin and Patient modes. |

---

## 📜 License  

This project is distributed under the [MIT License](./LICENSE).  
© 2025 **Abdelkerim El Bani** — All rights reserved.
