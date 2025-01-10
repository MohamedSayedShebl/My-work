import java.io.File;
import java.io.IOException;
import java.nio.file.NoSuchFileException;

public class Cd {
    private File workingDirectory;

    public void execute(String[] args) {
        try {
            if (args.length == 1) {
                cd(); // Change to home directory
            } else {
                cd(args[1]); // Change to the specified directory
            }
            System.out.println("Current Directory: " + getWorkingDirectory());
        } catch (NoSuchFileException e) {
            System.out.println(e.getMessage());
        } catch (IOException e) {
            System.out.println(e.getMessage());
        }
    }

    public Cd() {
        // Initialize the working directory to the user's home directory
        this.workingDirectory = new File(System.getProperty("user.home"));
    }

    public void cd(String sourcePath) throws NoSuchFileException, IOException {
        if (sourcePath.equals("..")) {
            // Navigate to the parent directory
            String parent = workingDirectory.getParent();
            if (parent != null) {
                workingDirectory = new File(parent).getAbsoluteFile();
            }
        } else {
            File f = makeAbsolute(sourcePath);
            if (!f.exists()) {
                throw new NoSuchFileException("The directory does not exist: " + f.getAbsolutePath());
            }
            if (!f.isDirectory()) {
                throw new IOException("Cannot change into a file: " + f.getAbsolutePath());
            } else {
                workingDirectory = f.getAbsoluteFile();
            }
        }
    }

    // Changes into the default directory (user's home)
    public void cd() {
        workingDirectory = new File(System.getProperty("user.home"));
    }

    private File makeAbsolute(String path) {
        // Converts the given path to an absolute path based on the current working directory
        File f = new File(path);
        return f.isAbsolute() ? f : new File(workingDirectory, path);
    }

    public String getWorkingDirectory() {
        return workingDirectory.getAbsolutePath();
    }
}