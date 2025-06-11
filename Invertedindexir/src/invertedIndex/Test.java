package invertedIndex;

import java.io.BufferedReader;
import java.io.File;
import java.io.IOException;
import java.io.InputStreamReader;

/**
 *
 * @author ehab
 */
public class Test {

    public static void main(String args[]) throws IOException {
        Index5 index = new Index5();
        //|**  change it to your collection directory 
        //|**  in windows "C:\\tmp11\\rl\\collection\\"       
        String files = "C:\\Users\\Moody Shebl\\Documents\\GitHub\\IR_InvertedIndex\\collection\\";

        File file = new File(files);
        //|** String[] 	list()
        //|**  Returns an array of strings naming the files and directories in the directory denoted by this abstract pathname.
        String[] fileList = file.list();

        if (fileList == null) {
            System.err.println("Error: Directory not found or empty -> " + files);
            return; // Exit if the directory is invalid
        }

        fileList = index.sort(fileList);
        index.N = fileList.length;

        for (int i = 0; i < fileList.length; i++) {
            fileList[i] = files + fileList[i];
        }
        index.buildIndex(fileList);
        index.store("index.txt");
        index.printDictionary();

        // String test3 = "data  should plain greatest comif"; // data  should plain greatest comif
        // System.out.println("Boo0lean Model result = \n" + index.find_24_01(test3));

        String phrase = "";

        do {
            System.out.println("Print search phrase: ");
            BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
            phrase = in.readLine();
            
            // *** Completed part ***
            if (!phrase.isEmpty()) {
                String result = index.find_24_01(phrase);
                System.out.println("Boolean Model result = \n" + result);
            }
            
        } while (!phrase.isEmpty());
        
        System.out.println("Exiting search.");
    }
}