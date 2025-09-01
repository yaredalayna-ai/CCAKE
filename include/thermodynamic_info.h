#ifndef THERMODYNAMIC_INFO_H
#define THERMODYNAMIC_INFO_H

namespace ccake{

/// @brief struct to hold thermodynamic info of the particle.
/// @details This struct holds the thermodynamic information of the particle.
/// those are: temperature, chemical potentials, energy density, 
/// entropy density, baryon density, strangeness density, electric charge 
/// density, pressure, speed of sound, enthalpy, and the derivatives of the
/// enthalpy with respect to the entropy density, baryon density, strangeness
/// density, and electric charge density.
/// @note: Beware these information needs to be passed to the cabana AoSoA. To this
/// end, we define helper macros at the bottom of this file. If one wants to
/// add a new member to this struct, one needs to add it to the macros as well.
/// Also, remmember to pass new datamembers to cabana AoSoA in
/// `SystemState::allocate_cababa_particles()`
struct thermodynamic_info
{
  // (T,mu_i) coordinates depend on which EoS was used!
  string eos_name = "";

  double T    = 0.0, muB  = 0.0, muS  = 0.0, muQ  = 0.0;
  double e    = 0.0, s    = 0.0, rhoB = 0.0, rhoS = 0.0, rhoQ = 0.0,
         p    = 0.0, cs2  = 0.0, w    = 0.0;
  double dwds = 0.0, dwdB = 0.0, dwdS = 0.0, dwdQ = 0.0;
  double dalpha_Bds = 0.0, dalpha_BdB = 0.0, dalpha_BdS = 0.0, dalpha_BdQ = 0.0;
  double dalpha_Sds = 0.0, dalpha_SdB = 0.0, dalpha_SdS = 0.0, dalpha_SdQ = 0.0;
  double dalpha_Qds = 0.0, dalpha_QdB = 0.0, dalpha_QdS = 0.0, dalpha_QdQ = 0.0;

};

namespace thermo_info{
  enum thermo_scalar_info{
    T,
    muB,
    muS,
    muQ,
    e,
    s,
    rhoB,
    rhoS,
    rhoQ,
    p,
    cs2,
    w,
    dwds,
    dwdB,
    dwdS,
    dwdQ,
    dalpha_Bds,
    dalpha_BdB,
    dalpha_BdS,
    dalpha_BdQ,
    dalpha_Sds,
    dalpha_SdB,
    dalpha_SdS,
    dalpha_SdQ,
    dalpha_Qds,
    dalpha_QdB,
    dalpha_QdS,
    dalpha_QdQ,
    NUM_THERMO_INFO
  };
#define THERMO_SCALAR_INFO double[ccake::thermo_info::NUM_THERMO_INFO]
}}

#endif