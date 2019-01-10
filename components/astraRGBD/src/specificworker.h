/*
 *    Copyright (C)2018 by YOUR NAME HERE
 *
 *    This file is part of RoboComp
 *
 *    RoboComp is free software: you can redistribute it and/or modify
 *    it under the terms of the GNU General Public License as published by
 *    the Free Software Foundation, either version 3 of the License, or
 *    (at your option) any later version.
 *
 *    RoboComp is distributed in the hope that it will be useful,
 *    but WITHOUT ANY WARRANTY; without even the implied warranty of
 *    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *    GNU General Public License for more details.
 *
 *    You should have received a copy of the GNU General Public License
 *    along with RoboComp.  If not, see <http://www.gnu.org/licenses/>.
 */

/**
       \brief
       @author authorname
*/



#ifndef SPECIFICWORKER_H
#define SPECIFICWORKER_H

#include <genericworker.h>
#include <innermodel/innermodel.h>
#include <MultiFrameListener.h>
#include <DoubleBufferConverters.h>


class SpecificWorker : public GenericWorker
{
Q_OBJECT
    int fps;

	astra::StreamSet streamSet;
    astra::StreamReader *reader;
	bool depthB,colorB, bodyB, pointB;
	MultiFrameListener *frameListener;

//	void initializeStreams();
//	void readFrame();

public:
	SpecificWorker(MapPrx& mprx);
	~SpecificWorker();
	void terminate();
	bool setParams(RoboCompCommonBehavior::ParameterList params);

	Registration RGBD_getRegistration();
	void RGBD_getData(imgType &rgbMatrix, depthType &distanceMatrix, RoboCompJointMotor::MotorStateMap &hState, RoboCompGenericBase::TBaseState &bState);
	void RGBD_getXYZ(PointSeq &points, RoboCompJointMotor::MotorStateMap &hState, RoboCompGenericBase::TBaseState &bState);
	void RGBD_getRGB(ColorSeq &color, RoboCompJointMotor::MotorStateMap &hState, RoboCompGenericBase::TBaseState &bState);
	TRGBDParams RGBD_getRGBDParams();
	void RGBD_getDepth(DepthSeq &depth, RoboCompJointMotor::MotorStateMap &hState, RoboCompGenericBase::TBaseState &bState);
	void RGBD_setRegistration(const Registration &value);
	void RGBD_getImage(ColorSeq &color, DepthSeq &depth, PointSeq &points, RoboCompJointMotor::MotorStateMap &hState, RoboCompGenericBase::TBaseState &bState);
	void RGBD_getDepthInIR(depthType &distanceMatrix, RoboCompJointMotor::MotorStateMap &hState, RoboCompGenericBase::TBaseState &bState);
	void HumanTracker_getJointsPosition(const int id, jointListType &jointList){};
	void HumanTracker_getRTMatrixList(const int id, RTMatrixList &RTMatList){};
	void HumanTracker_getUser(const int id, TPerson &user){};
	bool HumanTracker_getJointDepthPosition(const int idperson, const string &idjoint, joint &depthjoint);
	void HumanTracker_getUsersList(PersonList &users);
	void HumanTracker_getUserState(const int id, TrackingState &state){};

public slots:
	void compute();
	void initialize(int period);

private:
	InnerModel *innerModel;

};

#endif
