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


#include "DrivePID.h"
#include "../RobotMap.h"
#include "../OI.h"
// BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=INCLUDES
// END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=INCLUDES

// BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=CONSTANTS

    // END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=CONSTANTS

namespace{
 const int c_CPR = 512;
}

DrivePID::DrivePID() : PIDSubsystem("DrivePID", 0.0, 0.0, 0.0) {
    // BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=DECLARATIONS
    hopperLeft = RobotMap::driveHopperLeft;
    hopperRight = RobotMap::driveHopperRight;
    intakeLeft = RobotMap::driveIntakeLeft;
    intakeRight = RobotMap::driveIntakeRight;
    robotDrive41 = RobotMap::driveRobotDrive41;
    hLeft = RobotMap::driveHLeft;
    hRight = RobotMap::driveHRight;
//    leftEncoder = RobotMap::driveLeftEncoder;
//    rightEncoder = RobotMap::driveRightEncoder;
//    hEncoder = RobotMap::driveHEncoder;

    // END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=DECLARATIONS

    antiDriveTrain = RobotMap::driveAntiDriveTrain;
    gyro = RobotMap::m_gyro;

    //hopperLeft->SetEncPosition();
    hopperLeft->ConfigEncoderCodesPerRev(c_CPR);
    hopperLeft->ConfigPeakOutputVoltage(1.0, -1.0);
    hopperRight->ConfigEncoderCodesPerRev(c_CPR);
    hopperRight->ConfigPeakOutputVoltage(1.0, -1.0);
    hLeft->ConfigEncoderCodesPerRev(c_CPR);
    hLeft->ConfigPeakOutputVoltage(1.0, -1.0);
}

void DrivePID::InitDefaultCommand() {
    // Set the default command for a subsystem here.
    // SetDefaultCommand(new MySpecialCommand());
    // BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=DEFAULT_COMMAND


    // END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=DEFAULT_COMMAND
}

void DrivePID::SetSidePower(double move, double turn, double roll){ //no idea if this works
	robotDrive41->ArcadeDrive(move, turn);
	hLeft->Set(roll);
	hRight->Set(roll);
}


void DrivePID::DriveStraight(double power) {

	//std::cout << "Drive: Moving straight with power: " << power << std::endl;
	double correction = GetPIDController()->Get(); //Robot::drivePID->GetPIDOutput();
	SetSidePower(power, power + correction, 0);
	double degreesOff = GetSetpoint() - GetYaw();
	std::cout << "Correction: " << correction << "\tLeft: " <<
				(power - correction) << "\tRight: " << (power + correction) << "\tYaw: "
			<< GetYaw() << "\tSetpoint: " << GetSetpoint() <<  "\tOff By: " << degreesOff << std::endl;

}

void DrivePID::SetDirection(double heading)
{
	GetPIDController()->Disable();
	GetPIDController()->Reset();
    gyro.get()->ZeroYaw();
	GetPIDController()->SetSetpoint(heading); //we are now facing the same way the entire time
}

double DrivePID::ReturnPIDInput() {

	return GetYaw();

	// Return your input value for the PID loop
    // e.g. a sensor, like a potentiometer:
    // yourPot->SetAverageVoltage() / kYourMaxVoltage;
    // BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=SOURCE
     //   return driveEncoderRight->PIDGet();

    // END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=SOURCE
}

void DrivePID::UsePIDOutput(double output) {
	//std::cout << "DrivePID - UsePIDOutput = " << output << std::endl;

	robotDrive41.get()->TankDrive(-output, output);
	hLeft->Set(0);
	hRight->Set(0);
}


void DrivePID::DeployFeet(){
	antiDriveTrain->Set(true);
}

void DrivePID::RetractFeet(){
	antiDriveTrain->Set(false);
}

double DrivePID::GetLeftEncoder()
{
	//17.1.1 - Encoder position read 4x the CPR. So one revolution with 12 CPR will read the position as (12 * 4) = 48
	double encoderCounts = (double)(hopperLeft->GetEncPosition()/4);

	//Circumference = d*pi, d = 3.25inches, pi = 3.1415
	//Distance = (counts/CPR) * circumference
	double distance = (encoderCounts / c_CPR) * (3.25 * 3.1415);
	std::cout << "LeftEncoder distance: " << distance << std::endl;
	return distance;
	//Could make this return a distance once wheel size is known. Depends on how we use this
}

double DrivePID::GetRightEncoder()
{
	double encoderCounts = (double)(hopperRight->GetEncPosition()/4);

	double distance = (encoderCounts / c_CPR) * (3.25 * 3.1415);
	std::cout << "RightEncoder distance: " << distance << std::endl;
	return distance;
}

double DrivePID::GetHEncoder()
{
	double encoderCounts = (double)(hLeft->GetEncPosition()/4);

	double distance = (encoderCounts / c_CPR) * (3.25 * 3.1415);
	std::cout << "HEncoder distance: " << distance << std::endl;
	return distance;

}

double DrivePID::GetYaw() {
	return gyro->GetYaw();
}

void DrivePID::ResetEncoders(){
	hopperRight->Reset();
	hopperLeft->Reset();
	hLeft->Reset();
}

// Put methods for controlling this subsystem
// here. Call these from Commands.

