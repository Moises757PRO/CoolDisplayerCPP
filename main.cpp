int main(int argc, char* argv[]) {
    // ... (Argument validation) ...
    if (argc < 2) {
        cout << "ERROR!"
        return 1;
    }

    const char* TEXT = argv[1];
    const int FRAME_WIDTH = 7; // New total display width
    const int TEXT_LEN = std::strlen(TEXT);
    int J = 0; // The starting index for the scrolling window

    while (true) {
        clear_screen();

        // 1. Print the top frame line
        std::cout << "* * * *" << std::endl; // or use FRAME_WIDTH - 1 stars

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
        std::cout << " * * * " << std::endl;

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

