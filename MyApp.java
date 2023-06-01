import java.io.FileWriter;
java import java.io.File; 
import java.io.FileWriter; 
import java.io.IOException; 
import org.json.simple.JSONArray; 
import org.json.simple.JSONObject; 
public class MyApp { 
    public static void main(String[] args) { 
        JSONObject jsonObject = new JSONObject();
        // create a JSON object 
        // add user inputs to JSON object 
        jsonObject.put("input1", "value1"); 
        jsonObject.put("input2", "value2"); 
        jsonObject.put("input3", "value3"); 
        // write JSON object to file 
        try (FileWriter file = new FileWriter("output.json")){     
        file.write(jsonObject.toJSONString());
        System.out.println("Successfully wrote to output.json"); 
        } catch (IOException e) { e.printStackTrace(); 
        } 
    } 
} 