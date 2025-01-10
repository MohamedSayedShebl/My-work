import java.io.File;
import java.io.FileNotFoundException;
import java.util.Scanner;

public class CatCommand {
    public void execute(String[] args) {
        if (args.length < 1) {
            System.out.println("Usage: cat <file> [file2] ...");
            return;
        }

        for (String filename : args) {
            File file = new File(filename);

        if (!file.exists()) {
            System.out.println("Error: File does not exist.");
            return;
        }

        if (file.isDirectory()) {
            System.out.println("Error: Cannot read contents of a directory.");
            return;
        }

        try (Scanner scanner = new Scanner(file)) {
            while (scanner.hasNextLine()) {
                System.out.println(scanner.nextLine());
            }
        } catch (FileNotFoundException e) {
            System.out.println("Error: Could not open the file.");
        }
    }
  }
}
