// Ensemble.h created by Fahad Ali Khan
// Declares the Ensambles Class
// Ensemble class
#ifndef _ENSEMBLE_H_
#define _ENSEMBLE_H_
#include "Model.h"
#include <vector>
class Ensemble {
private:
    std::vector<Model*> models;

public:
    void addModel(Model* model) {
        models.push_back(model);
    }

    void removeModel(Model* model) {
        auto it = std::find(models.begin(), models.end(), model);
        if (it != models.end()) {
            models.erase(it);
        }
    }
    // Train the models
    int train() {
        int ret = 0;
        for (Model* model : models) {
            ret = model->train();
            if (ret != 0) {
                break;
            }
        }
        return ret;
    }



    double predict(double input) {
        double sum = 0;
        for (Model* model : models) {
            double prediction = model->predict(input);
            sum += prediction;
        }
        return sum / (int)models.size(); // Return average prediction
    }
};

#endif // !_ENSEMBLE_H_
