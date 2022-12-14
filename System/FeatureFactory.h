/**
   \file FeatureFactory.h
   \class FeatureFactory
   \brief In charge of creating different features for the Cell class.
   \details Provides an abstract interface for creating resource objects in a superclass. Allows subclasses to alter the type of resoucre that will be created
   Factory: Creator
   \defgroup FeatureFactory
   \author Megan Hugo
*/

#ifndef FEATUREFACTORY_H
#define FEATUREFACTORY_H

class CellFeatures;

class FeatureFactory {

public:
    /**
    * \fn FeatureFactory::createFeature
    * \return CellFeatures*
    * \brief virtual method to produce concrete product
    */
    virtual CellFeatures *createFeature() = 0;
};

#endif

#include "CellFeatures.h"
