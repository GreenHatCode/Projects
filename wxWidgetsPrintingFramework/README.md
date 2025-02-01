
# QucikPrint
This project is a simple way to print something using the wxWidgets print framework.

## Table of Contents

- [About](#about)
- [Installation](#installation)
- [Usage](#usage)

## About

This is a simple overloading of the wxPrintout class, which is part of the wxWidgets printing framework. I have implemented the drawing to the DC printer through a function that the user can pass through a pointer. This method allows you to write your own print function for each class whose data you want to print, so you don't need to overload wxPrintout for each of them.

## Installation

### Prerequisites

- Installed and configured wxWidgets framework
- C++14 or above

### Steps

1. Clone the repository:
    ```bash
    git clone https://github.com/GreenHatCode/Projects.git
    ```
2.  Change git remote url to avoid accidental pushes to base project
    ```bash
    git remote set-url origin github_username/repo_name
    git remote -v # confirm the changes
    ```
## Usage

### Example project
Open poject solution
	```
		Projects/QuickPrint/example_project/QuickPrintExample.sln
	```

Run debugging of the project. Once the project is compiled, you can test printing by pressing ``Ctrl + P``. By default, the wxWidgets logo is printed.

### Your project

 1. Add the ``QuickPrint.h`` and ``QuickPrint.cpp`` files to your solution.
 2. Add the ``void Print(wxDC& dc, int pageNum, wxSize pg_size)`` function to the class whose data you are going to print. It is recommended to look at the **example** and **wxWidgets documentation on drawing and printing**.
 3. Add a function to the window class to handle print events.
 4. Add code to this function as in the example project.


