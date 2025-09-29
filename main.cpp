* * *
hello
 * * ```

...your existing code **cannot produce that output** because:

1.  **It only prints the text, not the frame.** Your code is designed to print only the characters from the `TEXT` variable (`argv[1]`).
2.  **It doesn't handle multiple lines.** The output is always a single line followed by a newline `\n`.
3.  **It has a fixed window size.** Your code only prints 6 characters (`OUT_SIZE = 6`), but "HELLO" is only 5 characters.

To make your scrolling program display the output with the decorative frame, you need to completely **rewrite the printing logic** inside the main `while(true)` loop.

---

## Solution: Implementing the Framed Output

Here is how you modify the `main` loop to print a multi-line, framed output that centers the scrolling text.

### Key Changes to the Logic

1.  **Fixed Display Size:** I'll assume your full display frame is **7 characters wide** to comfortably fit "HELLO" (5 chars) plus two spaces/frame elements.
2.  **Printing the Frame:** We will use `std::cout` to print the frame lines before and after the scrolling text.
3.  **Centering/Wrapping the Text:** We'll use the modulo operation (`% TEXT_LEN`) exactly as before, but ensure we only print the number of characters required for the frame's center.

### Code Adjustments (Focusing on the `while` loop)

Here is the revised `main` function structure (assuming you keep all the necessary includes and platform-specific `my_sleep` and `clear_screen` functions):

```cpp
// ... (Includes, my_sleep, clear_screen, and main validation are the same) ...

int main(int argc, char* argv[]) {
    // ... (Argument validation) ...
    if (argc < 2) {
        // ... (Error message) ...
        return 1;
    }

    const char* TEXT = argv[1];
    const int FRAME_WIDTH = 7; // New total display width
    const int TEXT_LEN = std::strlen(TEXT);
    int J = 0; // The starting index for the scrolling window

    while (true) {
        clear_screen();

        // 1. Print the top frame line
        std::cout << "* * *" << std::endl; // or use FRAME_WIDTH - 1 stars

        // 2. Print the middle line (the scrolling text with padding)
        std::cout << " "; // Leading space for alignment

        // Scroll the text (J) and print only the required TEXT_LEN characters
        for (int i = 0; i < TEXT_LEN; i++) {
            int current_index = (J + i) % TEXT_LEN;
            std::cout << TEXT[current_index];
        }

        std::cout << " "; // Trailing space for alignment
        std::cout << std::endl;

        // 3. Print the bottom frame line
        std::cout << " * * " << std::endl;

        // 4. Wait and slide
        my_sleep(1);

        // This controls the scroll speed/step
        J++;
        
        // Optional: Ensure J doesn't grow infinitely (though harmless)
        if (J >= TEXT_LEN) {
            J = 0;
        }
    }
    
    return 0;
}
