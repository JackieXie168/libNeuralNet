/****************************************************************************************************************/
/*                                                                                                              */
/*   OpenNN: Open Neural Networks Library                                                                       */
/*   www.intelnics.com/opennn                                                                                   */
/*                                                                                                              */
/*   I N S T A N C E S   T E S T   C L A S S                                                                    */
/*                                                                                                              */ 
/*   Roberto Lopez                                                                                              */ 
/*   Intelnics - The artificial intelligence company                                                            */
/*   robertolopez@intelnics.com                                                                                 */
/*                                                                                                              */
/****************************************************************************************************************/

// Unit testing includes

#include "instances_test.h"

using namespace OpenNN;


// GENERAL CONSTRUCTOR

InstancesTest::InstancesTest(void) : UnitTesting() 
{
}


// DESTRUCTOR

InstancesTest::~InstancesTest(void)
{
}


// METHODS

void InstancesTest::test_constructor(void)
{
   message += "test_constructor\n";

   // Test

   Instances ii0;

   assert_true(ii0.get_instances_number() == 0, LOG);

   // Test

   Instances ii1(1);
  
   assert_true(ii1.count_training_instances_number() == 1, LOG);

   // Test

   Instances ii2(1);
   ii2.set_display(false);

   // Test

   Instances ii4;

   assert_true(ii4.count_training_instances_number() == 0, LOG);
   assert_true(ii4.count_generalization_instances_number() == 0, LOG);
   assert_true(ii4.count_testing_instances_number() == 0, LOG);

   Instances ii5(1);

   Instances ii6(ii5);

   assert_true(ii6.count_training_instances_number() == 1, LOG);
}


void InstancesTest::test_destructor(void)
{
   message += "test_destructor\n";

   Instances* iip = new Instances(1);

   delete iip;

}


void InstancesTest::test_assignment_operator(void)
{
   message += "test_assignment_operator\n";

   Instances ii1(1);
   Instances ii2 = ii1;

   assert_true(ii2.get_instances_number() == 1, LOG);   
}


void InstancesTest::test_get_instances_number(void) 
{
   message += "test_get_instances_number\n";

   Instances i;

   assert_true(i.get_instances_number() == 0, LOG);
}


void InstancesTest::test_count_training_instances_number(void) 
{
   message += "test_count_training_instances_number\n";

   Instances i;

   // Test

   i.set();

   assert_true(i.count_training_instances_number() == 0, LOG);

   // Test

   i.set(1);

   assert_true(i.count_training_instances_number() == 1, LOG);

}


void InstancesTest::test_arrange_training_indices(void) 
{
   message += "test_arrange_training_indices\n";

   Instances i;

   Vector<unsigned> training_indices;

   training_indices = i.arrange_training_indices();

   assert_true(training_indices.size() == 0, LOG);
   
   i.set(1);

   training_indices = i.arrange_training_indices();

   assert_true(training_indices.size() == 1, LOG);

}


void InstancesTest::test_count_generalization_instances_number(void) 
{
   message += "test_count_generalization_instances_number\n";

   Instances i;

   assert_true(i.count_generalization_instances_number() == 0, LOG);
   
   i.set(1);

   assert_true(i.count_generalization_instances_number() == 0, LOG);
}


void InstancesTest::test_arrange_generalization_indices(void) 
{
   message += "test_arrange_generalization_indices\n";

   Instances i;

   Vector<unsigned> generalization_indices;

   generalization_indices = i.arrange_generalization_indices();

   assert_true(generalization_indices.size() == 0, LOG);
   
   i.set(1);

   generalization_indices = i.arrange_generalization_indices();

   assert_true(generalization_indices.size() == 0, LOG);

}


void InstancesTest::test_count_testing_instances_number(void) 
{
   message += "test_count_testing_instances_number\n";

   Instances i;

   assert_true(i.count_testing_instances_number() == 0, LOG);
   
   i.set(1);

   assert_true(i.count_testing_instances_number() == 0, LOG);

}


void InstancesTest::test_arrange_testing_indices(void) 
{
   message += "test_arrange_testing_indices\n";
 
   Instances i;

   Vector<unsigned> testing_indices;

   testing_indices = i.arrange_testing_indices();

   assert_true(testing_indices.size() == 0, LOG);
   
   i.set(1);

   testing_indices = i.arrange_testing_indices();

   assert_true(testing_indices.size() == 0, LOG);
}


void InstancesTest::test_get_display(void) 
{
   message += "test_get_display\n";

   Instances i;

   i.set_display(true);

   assert_true(i.get_display() == true, LOG);

   i.set_display(false);

   assert_true(i.get_display() == false, LOG);
}


void InstancesTest::test_set(void) 
{
   message += "test_set\n";

   Instances i;

   // Instances and inputs and target variables

   i.set(1);

   assert_true(i.get_instances_number() == 1, LOG);
}


void InstancesTest::test_set_instances_number(void) 
{
   message += "test_set_instances_number\n";

   Instances i(1);

   i.set_instances_number(2);

   assert_true(i.get_instances_number() == 2, LOG);
}


void InstancesTest::test_set_training(void)
{
   message += "test_set_training\n";
   
   Instances i(1);
   i.set_training();

   assert_true(i.count_training_instances_number() == 1, LOG);
   assert_true(i.count_generalization_instances_number() == 0, LOG);
   assert_true(i.count_testing_instances_number() == 0, LOG);

   assert_true(i.arrange_training_indices() == 0, LOG);

}


void InstancesTest::test_set_generalization(void)
{
   message += "test_set_generalization\n";

   Instances i(1);
   i.set_generalization();

   assert_true(i.count_training_instances_number() == 0, LOG);
   assert_true(i.count_generalization_instances_number() == 1, LOG);
   assert_true(i.count_testing_instances_number() == 0, LOG);

   assert_true(i.arrange_generalization_indices() == 0, LOG);

}


void InstancesTest::test_set_testing(void)
{
   message += "test_set_testing\n";

   Instances i(1);
   i.set_testing();

   assert_true(i.count_training_instances_number() == 0, LOG);
   assert_true(i.count_generalization_instances_number() == 0, LOG);
   assert_true(i.count_testing_instances_number() == 1, LOG);

   assert_true(i.arrange_testing_indices() == 0, LOG);

}


void InstancesTest::test_set_display(void) 
{
   message += "test_set_display\n";
}


void InstancesTest::test_split_random_indices(void) 
{
   message += "test_split_random_indices\n";

   unsigned training_instances_number = 0;
   unsigned generalization_instances_number = 0;
   unsigned testing_instances_number = 0;

   Instances i(12);

   // All data for training

   i.split_random_indices(1.0, 0.0, 0.0);
  
   training_instances_number = i.count_training_instances_number();
   generalization_instances_number = i.count_generalization_instances_number();
   testing_instances_number = i.count_testing_instances_number();

   assert_true(training_instances_number == 12, LOG);
   assert_true(generalization_instances_number == 0, LOG);
   assert_true(testing_instances_number == 0, LOG);

   // All data for generalization 

   i.split_random_indices(0.0, 10.0, 0.0);
  
   training_instances_number = i.count_training_instances_number();
   generalization_instances_number = i.count_generalization_instances_number();
   testing_instances_number = i.count_testing_instances_number();

   assert_true(training_instances_number == 0, LOG);
   assert_true(generalization_instances_number == 12, LOG);
   assert_true(testing_instances_number == 0, LOG);

   // All data for testing 

   i.split_random_indices(0.0, 0.0, 100.0);
  
   training_instances_number = i.count_training_instances_number();
   generalization_instances_number = i.count_generalization_instances_number();
   testing_instances_number = i.count_testing_instances_number();

   assert_true(training_instances_number == 0, LOG);
   assert_true(generalization_instances_number == 0, LOG);
   assert_true(testing_instances_number == 12, LOG);

   // Split data for training, generalization and testing

   i.split_random_indices(0.5, 0.25, 0.25);
  
   training_instances_number = i.count_training_instances_number();
   generalization_instances_number = i.count_generalization_instances_number();
   testing_instances_number = i.count_testing_instances_number();

   assert_true(training_instances_number == 6, LOG);
   assert_true(generalization_instances_number == 3, LOG);
   assert_true(testing_instances_number == 3, LOG);

   // Split data for training, generalization and testing

   i.split_random_indices(2.0, 1.0, 1.0);
  
   training_instances_number = i.count_training_instances_number();
   generalization_instances_number = i.count_generalization_instances_number();
   testing_instances_number = i.count_testing_instances_number();

   assert_true(training_instances_number == 6, LOG);
   assert_true(generalization_instances_number == 3, LOG);
   assert_true(testing_instances_number == 3, LOG);

   // Test

   i.set_instances_number(10);
   i.split_random_indices();

   training_instances_number = i.count_training_instances_number();
   generalization_instances_number = i.count_generalization_instances_number();
   testing_instances_number = i.count_testing_instances_number();

   assert_true(training_instances_number == 6, LOG);
   assert_true(generalization_instances_number == 2, LOG);
   assert_true(testing_instances_number == 2, LOG);

}


void InstancesTest::test_split_sequential_indices(void)
{
   message += "test_split_sequential_indices\n";


  unsigned training_instances_number = 0;
  unsigned generalization_instances_number = 0;
  unsigned testing_instances_number = 0;

  Instances i(12);

  // All data for training

  i.split_sequential_indices(1.0, 0.0, 0.0);

  training_instances_number = i.count_training_instances_number();
  generalization_instances_number = i.count_generalization_instances_number();
  testing_instances_number = i.count_testing_instances_number();

  assert_true(training_instances_number == 12, LOG);
  assert_true(generalization_instances_number == 0, LOG);
  assert_true(testing_instances_number == 0, LOG);

  // All data for generalization

  i.split_sequential_indices(0.0, 10.0, 0.0);

  training_instances_number = i.count_training_instances_number();
  generalization_instances_number = i.count_generalization_instances_number();
  testing_instances_number = i.count_testing_instances_number();

  assert_true(training_instances_number == 0, LOG);
  assert_true(generalization_instances_number == 12, LOG);
  assert_true(testing_instances_number == 0, LOG);

  // All data for testing

  i.split_sequential_indices(0.0, 0.0, 100.0);

  training_instances_number = i.count_training_instances_number();
  generalization_instances_number = i.count_generalization_instances_number();
  testing_instances_number = i.count_testing_instances_number();

  assert_true(training_instances_number == 0, LOG);
  assert_true(generalization_instances_number == 0, LOG);
  assert_true(testing_instances_number == 12, LOG);

  // Split data for training, generalization and testing

  i.split_sequential_indices(0.5, 0.25, 0.25);

  training_instances_number = i.count_training_instances_number();
  generalization_instances_number = i.count_generalization_instances_number();
  testing_instances_number = i.count_testing_instances_number();

  assert_true(training_instances_number == 6, LOG);
  assert_true(generalization_instances_number == 3, LOG);
  assert_true(testing_instances_number == 3, LOG);

  // Split data for training, generalization and testing

  i.split_sequential_indices(2.0, 1.0, 1.0);

  training_instances_number = i.count_training_instances_number();
  generalization_instances_number = i.count_generalization_instances_number();
  testing_instances_number = i.count_testing_instances_number();

  assert_true(training_instances_number == 6, LOG);
  assert_true(generalization_instances_number == 3, LOG);
  assert_true(testing_instances_number == 3, LOG);

  // Test

  i.set_instances_number(10);
  i.split_sequential_indices();

  training_instances_number = i.count_training_instances_number();
  generalization_instances_number = i.count_generalization_instances_number();
  testing_instances_number = i.count_testing_instances_number();

  assert_true(training_instances_number == 6, LOG);
  assert_true(generalization_instances_number == 2, LOG);
  assert_true(testing_instances_number == 2, LOG);
}


void InstancesTest::test_to_XML(void) 
{
   message += "test_to_XML\n";

   Instances i;

   tinyxml2::XMLDocument* document = i.to_XML();

   assert_true(document != NULL, LOG);

   // Test

   i.set(2);

   i.set_use(0, Instances::Testing);
   i.set_use(1, Instances::Unused);

   document = i.to_XML();

   i.set();

   i.from_XML(*document);

   assert_true(i.get_instances_number() == 2, LOG);
   assert_true(i.get_use(0) == Instances::Testing, LOG);
   assert_true(i.get_use(1) == Instances::Unused, LOG);
}


void InstancesTest::test_from_XML(void) 
{
   message += "test_from_XML\n";

   Instances i;

   tinyxml2::XMLDocument* document = i.to_XML();
   
   i.from_XML(*document);

}


void InstancesTest::run_test_case(void)
{
   message += "Running instances test case...\n";

   // Constructor and destructor methods

   test_constructor();
   test_destructor();

   // Assignment operators methods

   test_assignment_operator();

   // Get methods

   test_get_instances_number();

   // Instances methods 

   test_count_training_instances_number();
   test_arrange_training_indices();

   test_count_generalization_instances_number();
   test_arrange_generalization_indices();

   test_count_testing_instances_number();
   test_arrange_testing_indices();

   test_get_display();

   // Set methods

   test_set();

   // Instances methods

   test_set_training();
   test_set_generalization();
   test_set_testing();

   test_set_display();

   // Data methods

   test_set_instances_number();

   // Splitting methods

   test_split_random_indices();
   test_split_sequential_indices();

   // Serialization methods

   test_to_XML();
   test_from_XML();

   message += "End of instances test case.\n";
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
