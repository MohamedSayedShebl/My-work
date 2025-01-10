import java.io.File;

public class RmCommand {
    public void execute(String[] args) {
        if (args.length != 1) {
            System.out.println("Usage: rm <file>");
            return;
        }

        File target = new File(args[0]);

        if (!target.exists()) {
            System.out.println("Error: File or directory does not exist.");
            return;
        }

        if (target.isDirectory()) {
            deleteDirectory(target);
        } else {
            if (target.delete()) {
                System.out.println("Successfully deleted file: " + target.getName());
            } else {
                System.out.println("Error: Could not delete the file.");
            }
        }
    }

    private void deleteDirectory(File directory) {
        File[] files = directory.listFiles();
        if (files != null) {
            for (File file : files) {
                if (file.isDirectory()) {
                    deleteDirectory(file);
                } else {
                    file.delete();
                }
            }
        }

        if (directory.delete()) {
            System.out.println("Successfully deleted directory: " + directory.getName());
        } else {
            System.out.println("Error: Could not delete the directory.");
        }
    }
}
