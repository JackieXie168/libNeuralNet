/****************************************************************************************************************/
/*                                                                                                              */
/*   OpenNN: Open Neural Networks Library                                                                       */
/*   www.intelnics.com/opennn                                                                                   */
/*                                                                                                              */
/*   T R A I N I N G   S T R A T E G Y   T E S T   C L A S S                                                    */
/*                                                                                                              */
/*   Roberto Lopez                                                                                              */
/*   Intelnics - The artificial intelligence company                                                            */
/*   robertolopez@intelnics.com                                                                                 */
/*                                                                                                              */
/****************************************************************************************************************/

// Unit testing includes

#include "training_strategy_test.h"

using namespace OpenNN;


// GENERAL CONSTRUCTOR 

TrainingStrategyTest::TrainingStrategyTest(void) : UnitTesting() 
{
}


// DESTRUCTOR

TrainingStrategyTest::~TrainingStrategyTest(void)
{
}


// METHODS

void TrainingStrategyTest::test_constructor(void)
{
   message += "test_constructor\n"; 

   PerformanceFunctional pf;

   // Test

   TrainingStrategy ts1(&pf); 

   assert_true(ts1.has_performance_functional() == true, LOG);

   // Test

   TrainingStrategy ts2; 

   assert_true(ts2.has_performance_functional() == false, LOG);
}


void TrainingStrategyTest::test_destructor(void)
{
   message += "test_destructor\n"; 

   TrainingStrategy* ts = new TrainingStrategy(); 

   delete ts;
}


void TrainingStrategyTest::test_get_performance_functional_pointer(void)
{
   message += "test_get_performance_functional_pointer\n"; 

   PerformanceFunctional pf;
   
   TrainingStrategy ts(&pf);

   PerformanceFunctional* pfp = ts.get_performance_functional_pointer();

   assert_true(pfp != NULL, LOG);
}


void TrainingStrategyTest::test_get_display(void)
{
   message += "test_get_warning_gradient_norm\n"; 

   TrainingStrategy ts;

   ts.set_display(false);

   assert_true(ts.get_display() == false, LOG);
}


void TrainingStrategyTest::test_set(void)
{
   message += "test_set\n"; 
}


void TrainingStrategyTest::test_set_default(void)
{
   message += "test_set_default\n"; 
}


void TrainingStrategyTest::test_set_performance_functional_pointer(void)
{
   message += "test_set_performance_functional_pointer\n"; 
}


void TrainingStrategyTest::test_set_display(void)
{
   message += "test_set_display\n"; 
}


void TrainingStrategyTest::test_perform_training(void)
{
   message += "test_perform_training\n";
}


void TrainingStrategyTest::test_to_XML(void)
{
   message += "test_to_XML\n";

   TrainingStrategy ts;

   // Test

   ts.set_initialization_type(TrainingStrategy::RANDOM_SEARCH);
   ts.set_main_type(TrainingStrategy::GRADIENT_DESCENT);
   ts.set_refinement_type(TrainingStrategy::NEWTON_METHOD);

   tinyxml2::XMLDocument* document = ts.to_XML();

   assert_true(document != NULL, LOG);

   delete document;

}


void TrainingStrategyTest::test_from_XML(void)
{
   message += "test_from_XML\n";

   TrainingStrategy ts1;
   TrainingStrategy ts2;

   ts1.set_initialization_type(TrainingStrategy::RANDOM_SEARCH);
   ts1.set_main_type(TrainingStrategy::GRADIENT_DESCENT);
   ts1.set_refinement_type(TrainingStrategy::NEWTON_METHOD);

   tinyxml2::XMLDocument* document = ts1.to_XML();

    ts2.from_XML(*document);

   delete document;

    assert_true(ts2.get_initialization_type() == TrainingStrategy::RANDOM_SEARCH, LOG);
    assert_true(ts2.get_main_type() == TrainingStrategy::GRADIENT_DESCENT, LOG);
    assert_true(ts2.get_refinement_type() == TrainingStrategy::NEWTON_METHOD, LOG);
}


void TrainingStrategyTest::test_print(void)
{
   message += "test_print\n";
}


void TrainingStrategyTest::test_save(void)
{
   message += "test_save\n";

   std::string file_name = "../data/training_strategy.xml";

   TrainingStrategy ts;

   ts.set_initialization_type(TrainingStrategy::RANDOM_SEARCH);
   ts.set_main_type(TrainingStrategy::GRADIENT_DESCENT);
   ts.set_refinement_type(TrainingStrategy::NEWTON_METHOD);

   ts.save(file_name);

}


void TrainingStrategyTest::test_load(void)
{
   message += "test_load\n";

   std::string file_name = "../data/training_strategy.xml";

   TrainingStrategy ts;

   // Test

   ts.initialize_random();

   ts.save(file_name);
   ts.load(file_name);

}


void TrainingStrategyTest::run_test_case(void)
{
   message += "Running training strategy test case...\n";

   // Constructor and destructor methods

   test_constructor();
   test_destructor();

   // Get methods

   test_get_performance_functional_pointer();

   // Utilities
   
   test_get_display();

   // Set methods

   test_set();
   test_set_default();   

   test_set_performance_functional_pointer();

   // Utilities

   test_set_display();

   // Training methods

   test_perform_training();

   // Serialization methods

   test_to_XML();
   test_from_XML();

   test_print();
   test_save();
   test_load();

   message += "End of training strategy test case.\n";
}


// OpenNN: Open Neural Networks Library.
// Copyright (C) 2005-2014 Roberto Lopez 
//
// This library is free software; you can redistribute it and/or
// modify it under the terms of the GNU Lesser General Public
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
