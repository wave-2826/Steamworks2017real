// RobotBuilder Version: 2.0
//
// This file was generated by RobotBuilder. It contains sections of
// code that are automatically generated and assigned by robotbuilder.
// These sections will be updated in the future when you export to
// C++ from RobotBuilder. Do not put any code or make any change in
// the blocks indicating autogenerated code or it will be lost on an
// update. Deleting the comments indicating the section will prevent
// it from being updated in the future.


#include "CANTalon.h"


#include "Drive.h"
#include "../RobotMap.h"
#include "../OI.h"
// BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=INCLUDES
// END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=INCLUDES

// BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=CONSTANTS

    // END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=CONSTANTS

Drive::Drive() : Subsystem("Drive") {
    // BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=DECLARATIONS
    hopperLeft = RobotMap::driveHopperLeft;
    hopperRight = RobotMap::driveHopperRight;
    intakeLeft = RobotMap::driveIntakeLeft;
    intakeRight = RobotMap::driveIntakeRight;
    robotDrive41 = RobotMap::driveRobotDrive41;
    hLeft = RobotMap::driveHLeft;
    hRight = RobotMap::driveHRight;
    leftEncoder = RobotMap::driveLeftEncoder;
    rightEncoder = RobotMap::driveRightEncoder;
    hEncoder = RobotMap::driveHEncoder;

    // END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=DECLARATIONS

    antiDriveTrain = RobotMap::driveAntiDriveTrain;
    gyro = RobotMap::m_gyro;

    //hopperLeft->SetEncPosition();
    hopperLeft->ConfigEncoderCodesPerRev(512);//_talon.ConfigEncoderCodesPerRev(XXX)
    hopperLeft->ConfigPeakOutputVoltage(1.0, -1.0);
    hopperRight->ConfigEncoderCodesPerRev(512);
    hopperRight->ConfigPeakOutputVoltage(1.0, -1.0);
    hLeft->ConfigEncoderCodesPerRev(512);
    hLeft->ConfigPeakOutputVoltage(1.0, -1.0);
}

void Drive::InitDefaultCommand() {
    // Set the default command for a subsystem here.
    // SetDefaultCommand(new MySpecialCommand());
    // BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=DEFAULT_COMMAND


    // END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=DEFAULT_COMMAND
}

void Drive::SetSidePower(double move, double turn, double roll){ //no idea if this works
	robotDrive41->ArcadeDrive(move, turn);
	hLeft->Set(roll);
	hRight->Set(roll);
}

void Drive::DeployFeet(){
	antiDriveTrain->Set(true);
}

void Drive::RetractFeet(){
	antiDriveTrain->Set(false);
}

std::shared_ptr<Encoder> Drive::GetLeftEncoder()
{
	return leftEncoder;
}

std::shared_ptr<Encoder> Drive::GetRightEncoder()
{
	return rightEncoder;
}

std::shared_ptr<Encoder> Drive::GetHEncoder()
{
	return hEncoder;
}

double Drive::GetYaw() {
	return gyro->GetYaw();
}

// Put methods for controlling this subsystem
// here. Call these from Commands.

