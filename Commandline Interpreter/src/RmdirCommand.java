import java.io.File;

public class RmdirCommand {
    public void execute(String[] args) {
        if (args.length != 1) {
            System.out.println("Usage: rmdir <directory>");
            return;
        }

        String dirPath = args[0];
        File dir = new File(dirPath);
        
            // Check if the directory exists
            if (!dir.exists()) {
                System.out.println("Error: The directory does not exist: " + dir.getAbsolutePath());
                return;
            }

            // Check if the path is a directory
            if (!dir.isDirectory()) {
                System.out.println("Error: The specified path is not a directory: " + dir.getAbsolutePath());
                return;
            }

            // Check if the directory is empty
            File[] files = dir.listFiles();
            if (files != null && files.length > 0) {
                System.out.println("Error: The directory is not empty: " + dir.getAbsolutePath());
                return;
            }

            // Remove the directory
            if (dir.delete()) {
                System.out.println("Directory removed: " + dir.getAbsolutePath());
            } else {
                System.out.println("Error: Could not remove the directory: " + dir.getAbsolutePath());
            }

        } 
    }
