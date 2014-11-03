/****************************************************************************************************************/
/*                                                                                                              */
/*   OpenNN: Open Neural Networks Library                                                                       */
/*   www.cimne.com/flood                                                                                        */
/*                                                                                                              */
/*   M O C K   T R A I N I N G   A L G O R I T H M   C L A S S                                                  */
/*                                                                                                              */
/*   Roberto Lopez                                                                                              */
/*   International Center for Numerical Methods in Engineering (CIMNE)                                          */
/*   Technical University of Catalonia (UPC)                                                                    */
/*   Barcelona, Spain                                                                                           */
/*   E-mail: rlopez@cimne.upc.edu                                                                               */
/*                                                                                                              */
/****************************************************************************************************************/


#include "mock_training_algorithm.h"

using namespace OpenNN;


// DEFAULT CONSTRUCTOR

MockTrainingAlgorithm::MockTrainingAlgorithm(void) : TrainingAlgorithm()
{
}



// GENERAL CONSTRUCTOR 

MockTrainingAlgorithm::MockTrainingAlgorithm(PerformanceFunctional* new_performance_functional_pointer)
: TrainingAlgorithm(new_performance_functional_pointer)
{
}


// DESTRUCTOR

MockTrainingAlgorithm::~MockTrainingAlgorithm(void)
{
}


// METHODS

// MockTrainingAlgorithmResults* perform_training(void) method

MockTrainingAlgorithm::MockTrainingAlgorithmResults* MockTrainingAlgorithm::perform_training(void)
{
   MockTrainingAlgorithmResults* mock_training_algorithm_training_results = new MockTrainingAlgorithmResults;

   return(mock_training_algorithm_training_results);
}


// OpenNN: Open Neural Networks Library.
// Copyright (C) 2005-2012 Roberto Lopez 
//
// This library is free software; you can redistribute it and/or
// modify it under the s of the GNU Lesser General Public
// License as published by the Free Software Foundation; either
// version 2.1 of the License, or any later version.
//
// This library is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
// Lesser General Public License for more details.

// You should have received a copy of the GNU Lesser General Public
// License along with this library; if not, write to the Free Software
// Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA  02110-1301  USA
