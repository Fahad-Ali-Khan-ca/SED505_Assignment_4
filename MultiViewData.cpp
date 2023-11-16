//MultiViewData.cpp - main function for the multi-view data

#include <vector>
//other includes'
#include <iostream>
#include "Ensemble.h"
#include "View.h"

int main() {

    View* ConsoleViewer = new ConsoleView;
    View* GraphicalViewer = new GraphicalView;

    Model Model1;
    Ensemble Ensembler;

    Ensembler.addModel(&Model1);
    int ret = 0;
    
    ret=Ensembler.train();
    // Add code

    if (ret == 0) {
        // Generate some random data and make predictions, five times
        const int TRIALS = 5;
        for (int i = 0; i < TRIALS; ++i) {
            const int NUM = 1000;
       //     for (int j = 0; j < NUM; ++j) {
       //         inputData.push_back((double)(rand() % 1000) / 1000);//generate a number between 0 and 1
       //     }  
       // my model uses single data points to make prediction
       // 
            double randomInput = static_cast<double>(rand() % 361); // Generate a random number between 0 and 360
            double prediction = Ensembler.predict(randomInput); // Make a prediction

            ConsoleViewer->displayPrediction(prediction); // Display using console view
            GraphicalViewer->displayPrediction(prediction); // Display using graphical view

            std::cout << std::endl;

            // Make a prediction using the trained model and display it in all views

            //clear out the vector for the next trial
            std::cout << std::endl;
        }
    }
    else {
        std::cerr << "Error in training the model." << std::endl;
    }
    // Add code --added

    delete ConsoleViewer;
    delete GraphicalViewer;
    return ret;
}