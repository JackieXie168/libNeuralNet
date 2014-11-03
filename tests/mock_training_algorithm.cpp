/****************************************************************************************************************/
/*                                                                                                              */
/*   OpenNN: Open Neural Networks Library                                                                       */
/*   www.intelnics.com/opennn                                                                                   */
/*                                                                                                              */
/*   M O C K   T R A I N I N G   A L G O R I T H M   C L A S S                                                  */
/*                                                                                                              */
/*   Roberto Lopez                                                                                              */
/*   Intelnics - The artificial intelligence company                                                            */
/*   robertolopez@intelnics.com                                                                                 */
/*                                                                                                              */
/****************************************************************************************************************/

// Unit testing includes

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


// tinyxml2::XMLDocument* to_XML(void) const method

tinyxml2::XMLDocument* MockTrainingAlgorithm::to_XML(void) const
{
   return(NULL);
}


// void from_XML(const tinyxml2::XMLDocument&) method

void MockTrainingAlgorithm::from_XML(const tinyxml2::XMLDocument&)
{
}


// OpenNN: Open Neural Networks Library.
// Copyright (C) 2005-2014 Roberto Lopez 
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
