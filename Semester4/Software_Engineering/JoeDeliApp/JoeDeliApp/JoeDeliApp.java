package hw1;
import javafx.application.Application;
import javafx.geometry.Insets;
import javafx.scene.Scene;
import javafx.scene.control.*;
import javafx.scene.layout.VBox;
import javafx.stage.Stage;

public class hw1 extends Application {
	// Prices for menu items
    private static final double EGG_SANDWICH_PRICE = 7.99;
    private static final double BAGEL_PRICE = 2.50;
    private static final double POTATO_SALAD_PRICE = 4.49;
    private static final double CHICKEN_SANDWICH_PRICE = 9.99;
    private static final double COFFEE_PRICE = 1.99;
    private static final double GREEN_TEA_PRICE = 0.99;
    private static final double BLACK_TEA_PRICE = 1.25;
    private static final double ORANGE_JUICE_PRICE = 2.25;
    private static final double SALES_TAX = 0.07; // 7%

    @Override
    public void start(Stage primaryStage) {
        primaryStage.setTitle("Joe's Deli");

        // Create food options
        CheckBox eggSandwich = new CheckBox("Egg Sandwich");
        CheckBox bagel = new CheckBox("Bagel");
        CheckBox potatoSalad = new CheckBox("Potato Salad");
        CheckBox chickenSandwich = new CheckBox("Chicken Sandwich");

        // Create drink options
        ToggleGroup drinkGroup = new ToggleGroup();
        RadioButton coffee = new RadioButton("Coffee");
        RadioButton greenTea = new RadioButton("Green Tea)");
        RadioButton blackTea = new RadioButton("Black Tea");
        RadioButton orangeJuice = new RadioButton("Orange Juice");

        coffee.setToggleGroup(drinkGroup);
        greenTea.setToggleGroup(drinkGroup);
        blackTea.setToggleGroup(drinkGroup);
        orangeJuice.setToggleGroup(drinkGroup);

        // Text area for displaying the bill
        TextArea billArea = new TextArea();
        billArea.setEditable(false);
        billArea.setPrefHeight(150);

        // Create buttons for ordering and canceling
        Button orderButton = new Button("Place Order");
        Button cancelButton = new Button("Clear Order");

        // Action for placing an order
        orderButton.setOnAction(e -> {
            StringBuilder bill = new StringBuilder("Your Order:\n");
            double total = 0;

            // Check selected food items
            if (eggSandwich.isSelected()) {
                bill.append("Egg Sandwich\n");
                total += EGG_SANDWICH_PRICE;
            }
            if (bagel.isSelected()) {
                bill.append("Bagel\n");
                total += BAGEL_PRICE;
            }
            if (potatoSalad.isSelected()) {
                bill.append("Potato Salad\n");
                total += POTATO_SALAD_PRICE;
            }
            if (chickenSandwich.isSelected()) {
                bill.append("Chicken Sandwich\n");
                total += CHICKEN_SANDWICH_PRICE;
            }

            // Check selected drink
            RadioButton selectedDrink = (RadioButton) drinkGroup.getSelectedToggle();
            if (selectedDrink != null) {
                String drinkText = selectedDrink.getText();
                bill.append(drinkText.split(" \\(")[0] + "\n");
                total += getDrinkPrice(drinkText);
            }

            // Calculate tax and total
            double tax = total * SALES_TAX;
            double finalTotal = total + tax;
            bill.append("\nSubtotal: $").append(String.format("%.2f", total));
            bill.append("\nTax: $").append(String.format("%.2f", tax));
            bill.append("\nTotal: $").append(String.format("%.2f", finalTotal));

            billArea.setText(bill.toString());
        });

        // Action for clearing the order
        cancelButton.setOnAction(e -> {
            eggSandwich.setSelected(false);
            bagel.setSelected(false);
            potatoSalad.setSelected(false);
            chickenSandwich.setSelected(false);
            drinkGroup.selectToggle(null);
            billArea.clear();
        });

        // Layout setup
        VBox root = new VBox(10);
        root.setPadding(new Insets(10));

        VBox foodBox = new VBox(5, eggSandwich, bagel, potatoSalad, chickenSandwich);
        VBox drinkBox = new VBox(5, coffee, greenTea, blackTea, orangeJuice);
        VBox buttonBox = new VBox(10, orderButton, cancelButton);

        root.getChildren().addAll(foodBox, drinkBox, billArea, buttonBox);

        Scene scene = new Scene(root, 300, 400);
        primaryStage.setScene(scene);
        primaryStage.show();
    }

    // Helper method to get drink price based on selection
    private double getDrinkPrice(String drinkText) {
        if (drinkText.contains("Coffee")) {
            return COFFEE_PRICE;
        } else if (drinkText.contains("Green Tea")) {
            return GREEN_TEA_PRICE;
        } else if (drinkText.contains("Black Tea")) {
            return BLACK_TEA_PRICE;
        } else if (drinkText.contains("Orange Juice")) {
            return ORANGE_JUICE_PRICE;
        }
        return 0;
    }

    public static void main(String[] args) {
        launch(args);
    }
}
