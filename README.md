# C++ OOP Bank Management System

A multi-tiered console-based banking application built in C++ using Object-Oriented Design principles. This project refactors a procedural banking setup into a modular, maintainable system featuring Role-Based Access Control (RBAC), authentication flows, and automated login auditing.

---

## Technical Overview & Features

- **Class Architecture & Inheritance:** Utilizes a decoupled design separating UI components (`clsScreen`), domain entities (`clsBankClient`, `clsUser`), and validation services.
- **Role-Based Access Control (RBAC):** Permission-bit mapping restricting access to specific menu actions depending on user roles.
- **Authentication & Security:** Login barrier with dynamic permission validation per operation and automated login attempt logging (`LoginRegister.txt`).
- **Client & Account Operations:** Complete CRUD operations for client accounts alongside core transaction mechanics (Deposits, Withdrawals, Transfers, and Balance summaries).
- **Custom Utility Modules:** Relies on dedicated helper classes like `clsInputValidate` for stream handling and type-safe input checks.
- **Data Persistence:** Handles record parsing, state synchronization, and flat-file updates for clients and user credentials.

---

## System Components

- `clsBankClient`: Handles client-related data logic, updates, and transaction execution.
- `clsUser`: Manages application users, authentication states, and system permission bitmasks.
- `clsScreen`: Base interface class providing structured headers and layout rules across all sub-screens.
- `clsInputValidate`: Input parsing library enforcing range, format, and type guarantees.
- **Sub-Screens:** Specialized execution modules for specific operations (`clsDepositScreen`, `clsTransferScreen`, `clsManageUsersScreen`, etc.).

---

## Setup & Execution

### Requirements
- C++11 compliant compiler (MSVC, GCC, or Clang)
- Visual Studio / VS Code or any compatible C++ IDE

### Steps
1. Clone repository:
   ```bash
   git clone [https://github.com/ayhamdeeb998-debug/Bank-System-OOP-Cpp.git](https://github.com/ayhamdeeb998-debug/Bank-System-OOP-Cpp.git)
