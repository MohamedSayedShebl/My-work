import org.junit.jupiter.api.Test;
import java.io.ByteArrayOutputStream;
import java.io.PrintStream;

import static org.junit.jupiter.api.Assertions.assertEquals;


public class PwdCommandTest {

    @Test
    public void testExecute() {
        ByteArrayOutputStream outputStream = new ByteArrayOutputStream();
        System.setOut(new PrintStream(outputStream));

        new PwdCommand().execute();


        String expectedOutput = System.getProperty("user.dir") + System.lineSeparator();
        assertEquals(expectedOutput, outputStream.toString());

        System.setOut(System.out);
    }
}
