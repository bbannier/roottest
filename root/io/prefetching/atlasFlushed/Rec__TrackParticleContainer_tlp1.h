//////////////////////////////////////////////////////////
//   This class has been generated by TFile::MakeProject
//     (Tue Jun 14 15:33:00 2011 by ROOT version 5.31/01)
//      from the StreamerInfo in file http://root.cern.ch/files/atlasFlushed.root
//////////////////////////////////////////////////////////


#ifndef Rec__TrackParticleContainer_tlp1_h
#define Rec__TrackParticleContainer_tlp1_h
namespace Rec {
class TrackParticleContainer_tlp1;
} // end of namespace.

#include "TPCnvTokenList_p1.h"
#include "Riostream.h"
#include <vector>
#include "Rec__TrackParticleContainer_p1.h"
#include "Rec__TrackParticle_p1.h"
#include "Trk__TrackParticleBase_p1.h"
#include "Trk__Track_p1.h"
#include "Trk__VxCandidate_p1.h"
#include "Trk__TrackParameters_p1.h"
#include "Trk__AtaSurface_p1.h"
#include "Trk__MeasuredAtaSurface_p1.h"
#include "Trk__Perigee_p1.h"
#include "Trk__MeasuredPerigee_p1.h"
#include "Trk__TrackSummary_p1.h"
#include "Trk__BoundSurface_p1.h"
#include "Trk__Surface_p1.h"
#include "Trk__CylinderBounds_p1.h"
#include "Trk__DiamondBounds_p1.h"
#include "Trk__DiscBounds_p1.h"
#include "Trk__RectangleBounds_p1.h"
#include "Trk__TrapezoidBounds_p1.h"
#include "Trk__RotatedTrapezoidBounds_p1.h"
#include "Trk__DetElementSurface_p1.h"
#include "Trk__FitQuality_p1.h"
#include "Trk__HepSymMatrix_p1.h"

namespace Rec {
class TrackParticleContainer_tlp1 {

public:
// Nested classes declaration.

public:
// Data Members.
   TPCnvTokenList_p1 m_tokenList;    //
   vector<Rec::TrackParticleContainer_p1> m_trackParticleContainer;    //(Rec::TrackParticleContainer_p1)
   vector<Rec::TrackParticle_p1>          m_trackParticle;             //(Rec::TrackParticle_p1)
   vector<Trk::TrackParticleBase_p1>      m_trackParticleBase;         //(Trk::TrackParticleBase_p1)
   vector<Trk::Track_p1>                  m_tracks;                    //(Trk::Track_p1)
   vector<Trk::VxCandidate_p1>            m_vxCandidates;              //(Trk::VxCandidate_p1)
   vector<Trk::TrackParameters_p1>        m_trackParameters;           //(Trk::TrackParameters_p1)
   vector<Trk::AtaSurface_p1>             m_ataSurfaces;               //(Trk::AtaSurface_p1)
   vector<Trk::MeasuredAtaSurface_p1>     m_measuredAtaSurfaces;       //(Trk::MeasuredAtaSurface_p1)
   vector<Trk::Perigee_p1>                m_perigees;                  //(Trk::Perigee_p1)
   vector<Trk::MeasuredPerigee_p1>        m_measPerigees;              //(Trk::MeasuredPerigee_p1)
   vector<Trk::TrackSummary_p1>           m_trackSummaries;            //(Trk::TrackSummary_p1)
   vector<Trk::BoundSurface_p1>           m_boundSurfaces;             //(Trk::BoundSurface_p1)
   vector<Trk::Surface_p1>                m_surfaces;                  //(Trk::Surface_p1)
   vector<Trk::CylinderBounds_p1>         m_cylinderBounds;            //(Trk::CylinderBounds_p1)
   vector<Trk::DiamondBounds_p1>          m_diamondBounds;             //(Trk::DiamondBounds_p1)
   vector<Trk::DiscBounds_p1>             m_discBounds;                //(Trk::DiscBounds_p1)
   vector<Trk::RectangleBounds_p1>        m_rectangleBounds;           //(Trk::RectangleBounds_p1)
   vector<Trk::TrapezoidBounds_p1>        m_trapesoidBounds;           //(Trk::TrapezoidBounds_p1)
   vector<Trk::RotatedTrapezoidBounds_p1> m_rotatedTrapesoidBounds;    //(Trk::RotatedTrapezoidBounds_p1)
   vector<Trk::DetElementSurface_p1>      m_detElementSurfaces;        //(Trk::DetElementSurface_p1)
   vector<Trk::FitQuality_p1>             m_fitQualities;              //(Trk::FitQuality_p1)
   vector<Trk::HepSymMatrix_p1>           m_hepSymMatrices;            //(Trk::HepSymMatrix_p1)

   TrackParticleContainer_tlp1();
   TrackParticleContainer_tlp1(const TrackParticleContainer_tlp1 & );
   virtual ~TrackParticleContainer_tlp1();

};
} // namespace
#endif