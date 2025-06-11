import tkinter as tk
from interface.gui import GomokuGUI

def main():
    root = tk.Tk()
    app = GomokuGUI(root)
    root.mainloop()

if __name__ == "__main__":
    main()

