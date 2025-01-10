import java.io.File;
import java.io.FileWriter;
import java.io.IOException;
import java.io.PrintWriter;

public class RedirectCommand {

    public void execute(String output, String filename) {
        
        // Get the output file name
        String outputFileName = filename;

        // Write the output to the specified file
        try (PrintWriter writer = new PrintWriter(new FileWriter(new File(outputFileName)))) {
            writer.print(output);
            System.out.println("Output redirected to '" + outputFileName + "'.");
        } catch (IOException e) {
            System.out.println("Error: Unable to write to file '" + outputFileName + "'.");
        }
    }
}