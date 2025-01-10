import java.io.File;
import java.io.IOException;
import java.nio.file.Files;
import java.nio.file.StandardCopyOption;

public class MvCommand {
    public void execute(String[] args) {
        if (args.length != 2) {
            System.out.println("Usage: mv <source> <destination>");
            return;
        }

        File source = new File(args[0]);
        File destination = new File(args[1]);

        if (!source.exists()) {
            System.out.println("Error: Source file or directory does not exist.");
            return;
        }

        // Handle case where the destination is a directory
        if (destination.isDirectory()) {
            destination = new File(destination, source.getName());
        }

        try {
            if (source.isDirectory()) {
                // Attempt directory move using renameTo
                if (!source.renameTo(destination)) {
                    System.out.println("Error: Could not move the directory. Possible cross-filesystem issue.");
                } else {
                    System.out.println("Successfully moved directory: " + source.getName() + " to " + destination.getPath());
                }
            } else {
                // Convert File to Path using toPath() and StandardCopyOption.REPLACE_EXISTING to handle overwriting case
                Files.move(source.toPath(), destination.toPath(), StandardCopyOption.REPLACE_EXISTING);
                System.out.println("Successfully moved/renamed file: " + source.getName() + " to " + destination.getPath());
            }
        } catch (IOException e) {
            System.out.println("Error: Could not move or rename due to an I/O error.");
        }
    }
}

