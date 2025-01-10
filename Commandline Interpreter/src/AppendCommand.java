import java.io.File;
import java.io.FileWriter;
import java.io.IOException;

public class AppendCommand {
    public void execute(String[] args) {
        if (args.length < 2) {
            System.out.println("Usage: >> <file> <text to append>");
            return;
        }

        File file = new File(args[0]);

        StringBuilder textToAppend = new StringBuilder();
        for (int i = 1; i < args.length; i++) {
            textToAppend.append(args[i]).append(" ");
        }

        try (FileWriter writer = new FileWriter(file, true)) {
            writer.write(textToAppend.toString().trim() + System.lineSeparator());
            System.out.println("Text appended to file: " + file.getName());
        } catch (IOException e) {
            System.out.println("Error: Could not append to the file.");
        }
    }
}
