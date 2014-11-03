/****************************************************************************************************************/
/*                                                                                                              */
/*   OpenNN: Open Neural Networks Library                                                                      */
/*   www.opennn.cimne.com                                                                                       */
/*                                                                                                              */
/*   U N I T   T E S T I N G   C L A S S   H E A D E R                                                          */
/*                                                                                                              */
/*   Roberto Lopez                                                                                              */ 
/*   International Center for Numerical Methods in Engineering (CIMNE)                                          */
/*   Technical University of Catalonia (UPC)                                                                    */
/*   Barcelona, Spain                                                                                           */
/*   E-mail: rlopez@cimne.upc.edu                                                                               */ 
/*                                                                                                              */
/****************************************************************************************************************/

#ifndef __UNITTESTING_H__
#define __UNITTESTING_H__

// OpenNN includes

#include "../source/utilities/vector.h"
#include "../source/utilities/matrix.h"


class UnitTesting
{

public:

   // DEFAULT CONSTRUCTOR

   explicit UnitTesting(void);

   // DESTRUCTOR

   virtual ~UnitTesting(void);

   // METHODS

   // Get methods

   unsigned int get_tests_count(void) const;
   unsigned int get_tests_passed_count(void) const;
   unsigned int get_tests_failed_count(void) const;

   bool get_numerical_differentiation_tests(void) const;
   unsigned int get_random_tests_number(void) const;

   std::string& get_message(void);

   const bool& get_display(void) const;

   // Set methods

   void set_tests_count(const unsigned int&);
   void set_tests_passed_count(const unsigned int&);
   void set_tests_failed_count(const unsigned int&);

   void set_numerical_differentiation_tests(const bool&);
   void set_random_tests_number(const unsigned int&);

   void set_message(const std::string&);

   void set_display(const bool&);

   // Unit testing methods

   void assert_true(const bool&, const std::string&);
   void assert_false(const bool&, const std::string&);
   
   // Test case methods

   /// This method runs all the methods contained in the test case. 

   virtual void run_test_case(void) = 0;

   void print_results(void);

protected:

   // Number of performed tests. 

   unsigned int tests_count;

   // Number of tests which have passed the test case. 
 
   unsigned int tests_passed_count;

   // Number of tests which have failed the test case. 

   unsigned int tests_failed_count;

   // True if test using numerical differentiation are to be performed. 

   bool numerical_differentiation_tests;

   // Number of iterations in random tests loops. 

   unsigned int random_tests_number;

   // String with the test case information.

   std::string message;

   // True if messages from this class are to be displayed, false otherwise. 

   bool display;
};

#endif

// OpenNN: Open Neural Networks Library.
// Copyright (C) 2005-2012 Roberto Lopez 
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
