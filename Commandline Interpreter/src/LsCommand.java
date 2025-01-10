import java.io.File;
import java.util.Arrays;

public class LsCommand {
    public void execute(String[] args) {
        File currentDir = new File(System.getProperty("user.dir"));
        File[] files = currentDir.listFiles();

        if (files == null) {
            System.out.println("Error: Unable to list files.");
            return;
        }

        boolean show = false;
        boolean reverse = false;
        for (String arg : args) {
            if (arg.equals("-a")) {
                show = true;
            } else if (arg.equals("-r")) {
                reverse = true;
            }
        }

        if (!show) {
            files = Arrays.stream(files)
                          .filter(file -> !file.isHidden())
                          .toArray(File[]::new);
        }

        Arrays.sort(files, (f1, f2) -> f1.getName().compareToIgnoreCase(f2.getName()));

        if (reverse) {
            for (int i = files.length - 1; i >= 0; i--) {
                System.out.println(files[i].getName());
            }
        } else {
            for (File file : files) {
                System.out.println(file.getName());
            }
        }
    }
}
