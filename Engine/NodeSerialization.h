//  Natron
//
/* This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/. */
/*
*Created by Alexandre GAUTHIER-FOICHAT on 6/1/2012.
*contact: immarespond at gmail dot com
*
*/

#ifndef NODESERIALIZATION_H
#define NODESERIALIZATION_H

#include <string>

#include "Global/Macros.h"
CLANG_DIAG_OFF(unused-parameter)
// /opt/local/include/boost/serialization/smart_cast.hpp:254:25: warning: unused parameter 'u' [-Wunused-parameter]
#include <boost/archive/xml_iarchive.hpp>
CLANG_DIAG_ON(unused-parameter)
#include <boost/archive/xml_oarchive.hpp>
#include <boost/serialization/vector.hpp>
#include <boost/serialization/list.hpp>
#include <boost/serialization/version.hpp>

#include "Engine/KnobSerialization.h"
namespace Natron {
    class Node;
}

class NodeSerialization {
    
    
public:
    
    typedef std::list< KnobSerialization > KnobValues;
    
    NodeSerialization() : _isNull(true) {}
    
    ~NodeSerialization(){ _knobsValues.clear(); _inputs.clear(); }
    
    void initialize(Natron::Node* n);
    
    const KnobValues& getKnobsValues() const {return _knobsValues;}
    
    const std::string& getPluginLabel() const {return _pluginLabel;}
    
    const std::string& getPluginID() const {return _pluginID;}
    
    const std::vector<std::string>& getInputs() const {return _inputs;}
    
    int getPluginMajorVersion() const { return _pluginMajorVersion; }
    
    int getPluginMinorVersion() const { return _pluginMinorVersion; }
    
    bool isNull() const { return _isNull; }
    
    U64 getKnobsAge() const { return _knobsAge; }
    
    const std::string& getMasterNodeName() const { return _masterNodeName; }
private:
    
    bool _isNull;
    KnobValues _knobsValues;
    U64 _knobsAge;
    std::string _pluginLabel;
    std::string _pluginID;
    int _pluginMajorVersion;
    int _pluginMinorVersion;
    std::string _masterNodeName;
    
    std::vector<std::string> _inputs;

    
    friend class boost::serialization::access;
    template<class Archive>
    void save(Archive & ar, const unsigned int version) const
    {
        (void)version;
        ar & boost::serialization::make_nvp("Plugin_label",_pluginLabel);
        ar & boost::serialization::make_nvp("Plugin_id",_pluginID);
        ar & boost::serialization::make_nvp("Plugin_major_version",_pluginMajorVersion);
        ar & boost::serialization::make_nvp("Plugin_minor_version",_pluginMinorVersion);
        ar & boost::serialization::make_nvp("Knobs_values_map", _knobsValues);
        ar & boost::serialization::make_nvp("Inputs_map",_inputs);
        ar & boost::serialization::make_nvp("KnobsAge",_knobsAge);
        ar & boost::serialization::make_nvp("MasterNode",_masterNodeName);
        
    }
    
    template<class Archive>
    void load(Archive & ar, const unsigned int version)
    {
        (void)version;
        ar & boost::serialization::make_nvp("Plugin_label",_pluginLabel);
        ar & boost::serialization::make_nvp("Plugin_id",_pluginID);
        ar & boost::serialization::make_nvp("Plugin_major_version",_pluginMajorVersion);
        ar & boost::serialization::make_nvp("Plugin_minor_version",_pluginMinorVersion);
        ar & boost::serialization::make_nvp("Knobs_values_map", _knobsValues);
        ar & boost::serialization::make_nvp("Inputs_map",_inputs);
        ar & boost::serialization::make_nvp("KnobsAge",_knobsAge);
        ar & boost::serialization::make_nvp("MasterNode",_masterNodeName);
        _isNull = false;
        
    }
    BOOST_SERIALIZATION_SPLIT_MEMBER()

    
};

BOOST_CLASS_VERSION(NodeSerialization, 1)


#endif // NODESERIALIZATION_H
