#!/bin/bash
#SBATCH --job-name=singularity-mpi
#SBATCH --nodes=1
#SBATCH --ntasks=2
#SBATCH --time=00:05:00
#SBATCH --output=output_file.txt
#SBATCH --partition=g100_all_serial

module load openmpi

export HWLOC_COMPONENTS=-gl
export OMPI_MCA_btl=^openib

mpirun -n 2 singularity run mat_mul