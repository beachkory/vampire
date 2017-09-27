//------------------------------------------------------------------------------
//
//   This file is part of the VAMPIRE open source package under the
//   Free BSD licence (see licence file for details).
//
//   (c) Sarah Jenkins 2016. All rights reserved.
//
//   Email: sj681@york.ac.uk
//
//------------------------------------------------------------------------------
//

// C++ standard library headers
#include <iostream>

// Vampire headers
#include "environment.hpp"

// environment module headers
#include "internal.hpp"
#ifdef FFT
#include <fftw3.h>
#endif
namespace environment{

   //------------------------------------------------------------------------------
   // Externally visible variables
   //------------------------------------------------------------------------------
   std::vector < double > environment_field_x;
   std::vector < double > environment_field_y;
   std::vector < double > environment_field_z;

   std::vector < double > atomic_field_x;
   std::vector < double > atomic_field_y;
   std::vector < double > atomic_field_z;

   int demag_update_rate = 1000;
   bool enabled = false;

   int num_atomic_steps_env= 1;

   std::vector < int > list_of_mm_cells_with_neighbours;
   std::vector < int > list_of_env_cells_with_neighbours;
   std::vector < double > list_of_overlap_area;

   int num_interactions = 0;


   namespace internal{

      //------------------------------------------------------------------------
      // Shared variables inside environment module
      //------------------------------------------------------------------------

      std::vector < double > dim(3,6.0);
      std::vector < double > cell_size(3,2.0);

      std::vector < double > initial_spin(3,0.0);

      std::vector < double > ext_field(3,0.0);

      std::vector < double > dipole_field_x;
      std::vector < double > dipole_field_y;
      std::vector < double > dipole_field_z;

      std::vector < double > shift(3,0.0);
      double eightPI_three_cell_volume;
      double cell_volume;

      bool random_spins = true;

      double one_o_chi_para;
      double one_o_chi_perp;

      int num_cells;
      double A = -180;
      double ku= -1e-23;
      double Tc = 600;
      double Ms = 1e-21;
      double gamma = 1.0;
      double alpha = 1.0;
      int num_env_cells = 0.0;
      double m_e;
      double exchange_constant;
      double alpha_para;
      double alpha_perp;

      std::vector < double > x_mag_array;//arrays to store the cell magnetidsation
      std::vector < double > y_mag_array;
      std::vector < double > z_mag_array;

      std::vector<double> cell_coords_array_x; /// arrays to store cells positions
      std::vector<double> cell_coords_array_y;
      std::vector<double> cell_coords_array_z;

      std::vector<double> neighbour_list_start_index;   //arrays to store the neighbour lists
      std::vector<double> neighbour_list_end_index;
      std::vector<double> neighbour_list_array;

      ofstream o_file;

      //if FFT is enabled at compilation
      #ifdef FFT
      fftw_complex *N2xx0; //3D Array for dipolar field
      fftw_complex *N2xy0;
      fftw_complex *N2xz0;

      fftw_complex *N2yx0; //3D Array for dipolar field
      fftw_complex *N2yy0;
      fftw_complex *N2yz0;

      fftw_complex *N2zx0; //3D Array for dipolar field
      fftw_complex *N2zy0;
      fftw_complex *N2zz0;

      fftw_complex *N2xx; //3D Array for dipolar field
      fftw_complex *N2xy;
      fftw_complex *N2xz;

      fftw_complex *N2yx; //3D Array for dipolar field
      fftw_complex *N2yy;
      fftw_complex *N2yz;

      fftw_complex *N2zx; //3D Array for dipolar field
      fftw_complex *N2zy;
      fftw_complex *N2zz;

      fftw_complex *Mx_in; //3D Array for magnetisation into FT
      fftw_complex *My_in;
      fftw_complex *Mz_in;

      fftw_complex *Hx_in; //3D Array for field into FT
      fftw_complex *Hy_in;
      fftw_complex *Hz_in;

      fftw_complex *Mx_out; //3D Array for magnetisation storage out for FT
      fftw_complex *My_out;
      fftw_complex *Mz_out;

      fftw_complex *Hx_out; //3D Array for field out of FT
      fftw_complex *Hy_out;
      fftw_complex *Hz_out;
      #endif

      //ints to store the numbers of cells
      int num_cells_x;
      int num_cells_y;
      int num_cells_z;

      int eight_num_cells;

      std::vector < int > none_atomistic_cells;
      std::vector < int > atomistic_cells;
      std::vector < int > list_env_cell_atomistic_cell;
      std::vector < int > env_cell_is_in_atomistic_region;

   } // end of internal namespace

} // end of environment namespace
