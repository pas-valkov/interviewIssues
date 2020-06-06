package main;

import java.io.File;

import java.io.FileWriter;
import java.io.IOException;

import java.util.ArrayList;
import java.util.Collections;
import java.util.Comparator;
import java.util.HashMap;
import java.util.Scanner;

public class TextSorting {
    public static void main (String[] args) {
        commandArgsIsOk(args);
        
        ArrayList<String> strs = getTextFromFile(args[1]);
        HashMap<String, Integer> stringCount = countEqualStrings(strs);
        
        switch (args[2]) {
            case "1":
                sortByAlpha(strs);
                break;
            case "2":
                sortBySumbolNumber(strs);
                break;
            case "3":
                int wordNumber = Integer.parseInt(args[3]) - 1;
                for (String s: strs) {
                    if (s.split(" ").length <= wordNumber) {
                        throw new IllegalArgumentException("Wrong argument: " + args[3]);
                    }
                }
                if (wordNumber < 0) {
                    throw new IllegalArgumentException("Wrong argument: " + args[3]);
                }
                sortByWord(strs, wordNumber);
        }
        writeToFile(strs, stringCount, args[0]);
    }
    
    public static void commandArgsIsOk (String[] args) {
        if ((args.length != 3) && (args.length != 4)) {
            throw new IllegalArgumentException("Wrong number of command arguments");
        }
        else {
            if (args[2].equals("3")) {
                Integer.parseInt(args[3]);
                if (args.length != 4)
                    throw new IllegalArgumentException("Wrong number of command arguments");
            }
            else if ((args[2].equals("1")) || (args[2].equals("2")))
                if (args.length != 3)
                    throw new IllegalArgumentException("Wrong number of command arguments");
        }
    }
    
    public static ArrayList<String> getTextFromFile (String inputFileName) {
        ArrayList<String> strs = new ArrayList<>();
        try {
            Scanner sc = new Scanner(new File(inputFileName));
            while (sc.hasNext()) {
                strs.add(sc.nextLine());
            }
            sc.close();
        }
        catch (IOException e) {
            e.printStackTrace();
        }
        return strs;
    }
    
    public static HashMap<String, Integer> countEqualStrings (ArrayList<String> strs) {
        HashMap<String, Integer> stringCount = new HashMap<>();
        for (String s: strs) {
            if (stringCount.containsKey(s))
                stringCount.put(s, stringCount.get(s) + 1);
            else
                stringCount.put(s, 1);
        }
        return stringCount;
    }
    
    public static void sortByAlpha(ArrayList<String> strs) {
        Collections.sort(strs);
    }
    
    public static void sortBySumbolNumber(ArrayList<String> strs) {
        Collections.sort(strs, new Comparator<String>() {
            @Override
            public int compare(String s1, String s2) {
                return s2.length() - s1.length();
            }
        });
    }
    
    public static void sortByWord(ArrayList<String> strs, int wordNumber) {
        strs.sort((p1, p2) -> p1.split(" ")[wordNumber].compareTo(p2.split(" ")[wordNumber]));
    }
    
    public static void writeToFile (ArrayList<String> strs, HashMap<String, Integer> stringCount, String outputFileName) {
        try {
            FileWriter myWriter = new FileWriter(outputFileName);
            for (String s: strs) {
                myWriter.write(s + " " + stringCount.get(s) + '\n');
            }
            myWriter.close();
        }
        catch (IOException e) {
              System.out.println("An error occurred");
              e.printStackTrace();
        }
    }
    
}
