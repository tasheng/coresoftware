#ifndef G4CALO_HCALRAWTOWERBUILDER_H
#define G4CALO_HCALRAWTOWERBUILDER_H

#include <fun4all/SubsysReco.h>

#include <phparameter/PHParameterInterface.h>

#include <cmath>
#include <string>

class PHCompositeNode;
class RawTowerContainer;
class RawTowerGeomContainer;

class HcalRawTowerBuilder : public SubsysReco, public PHParameterInterface
{
 public:
  HcalRawTowerBuilder(const std::string &name = "HcalRawTowerBuilder");
  ~HcalRawTowerBuilder() override {}

  int InitRun(PHCompositeNode *topNode) override;
  int process_event(PHCompositeNode *topNode) override;
  void Detector(const std::string &d) { m_Detector = d; }
  void EminCut(const double e) { m_Emin = e; }
  void checkenergy(const int i = 1) { m_ChkEnergyConservationFlag = i; }

  enum enu_tower_energy_src
  {
    //! save Geant4 energy deposition as the weight of the cells
    kEnergyDeposition,

    //! save light yield as the weight of the cells
    kLightYield,

    //! save ionization energy
    kIonizationEnergy,
    //! initialization value
    unknown = -1
  };

  int get_tower_energy_src() const
  {
    return m_TowerEnergySrc;
  }

  std::string
  get_sim_tower_node_prefix() const
  {
    return m_SimTowerNodePrefix;
  }

  void
  set_sim_tower_node_prefix(const std::string &simTowerNodePrefix)
  {
    m_SimTowerNodePrefix = simTowerNodePrefix;
  }

  short get_tower_row(const short cellrow) const;

  void set_decal_filename(const std::string &fname) {m_DeCalibrationFileName = fname;}

  void SetDefaultParameters() override;

  void set_cell_decal_factor(const int etabin, const int phibin, const double d);
  void set_tower_decal_factor(const int etabin, const int phibin, const double d);

 private:
  void CreateNodes(PHCompositeNode *topNode);
  void ReadParamsFromNodeTree(PHCompositeNode *topNode);
  void SetTowerDecalFactors();
  void set_tower_decal_factor_real(const int etabin, const int phibin, const double d);

  RawTowerContainer *m_Towers = nullptr;
  RawTowerGeomContainer *m_RawTowerGeom = nullptr;

  double m_Emin = NAN;
  int m_ChkEnergyConservationFlag = 0;
  int m_TowerEnergySrc = enu_tower_energy_src::unknown;
  int m_NcellToTower = -1;

  std::string m_Detector = "NONE";
  std::string m_TowerNodeName;
  std::string m_TowerGeomNodeName;
  std::string m_SimTowerNodePrefix;
  std::string m_DeCalibrationFileName;

  std::array< std::array<double,320>, 24> m_DecalArray;
  std::map<std::pair<int,int>,double> m_TowerDecalFactors;
};

#endif /* G4CALO_HCALRAWTOWERBUILDER_H */
