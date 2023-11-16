// View.h
#ifndef VIEW_H_
#define VIEW_H_

#include <iostream>

class View {
public:
    virtual ~View() = default; // Virtual destructor
    virtual void displayPrediction(double prediction) = 0; // Single function for displaying predictions
};

// I decided to add these classes here since there is not much to do 
// and making seperate header and cpp file would be less efficient
class ConsoleView : public View {
public:
    void displayPrediction(double prediction) override {
        std::cout << "Console Prediction: " << prediction << std::endl;
    }
};

class GraphicalView : public View {
public:
    void displayPrediction(double prediction) override {
        std::cout << "Graphical Prediction: " << prediction << std::endl;
    }
};

#endif // VIEW_H_
