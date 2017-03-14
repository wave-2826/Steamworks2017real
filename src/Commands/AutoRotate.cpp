// RobotBuilder Version: 2.0
//
// This file was generated by RobotBuilder. It contains sections of
// code that are automatically generated and assigned by robotbuilder.
// These sections will be updated in the future when you export to
// C++ from RobotBuilder. Do not put any code or make any change in
// the blocks indicating autogenerated code or it will be lost on an
// update. Deleting the comments indicating the section will prevent
// it from being updated in the future.


#include "AutoRotate.h"

// BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=CONSTRUCTOR

AutoRotate::AutoRotate(double heading, double power, double timeout): Command() {
	Requires(Robot::drivePID.get());
        // Use requires() here to declare subsystem dependencies
    // eg. requires(Robot::chassis.get());
    // BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=REQUIRES
    // END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=REQUIRES
	m_heading = heading;
	m_power = power;

	if(timeout != 0)
	{
		SetTimeout(timeout);
	}
}

    // END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=CONSTRUCTOR

// Called just before this Command runs the first time
void AutoRotate::Initialize() {

//	Robot::drivePID->SetPIDs(c_straightP, c_straightI, c_straightD);
	Robot::drivePID->SetPIDs(c_turnP, c_turnI, c_turnD);

	Robot::drivePID->ArcadeDrive(0, m_power, m_heading);
	std::cout << " Done" << std::endl;
}

// Called repeatedly when this Command is scheduled to run
void AutoRotate::Execute() {
	std::cout << "Heading Dif:" << (m_heading - Robot::drivePID->GetYaw()) << ", Want: " << m_heading << ", At: " << Robot::drivePID->GetYaw() <<
			" Auto Rotate Execute _-------------------------" << std::endl;
	Robot::drivePID->ArcadeDrive(.1, m_power, m_heading);

	}

// Make this return true when this Command no longer needs to run execute()
bool AutoRotate::IsFinished() {
	//Check to see if encoder reads that we've traveled the distance
//
	//if(((m_heading - Robot::drivePID->GetYaw()) < 1) && ((m_heading - Robot::drivePID->GetYaw()) > -1)){
	if(IsTimedOut())
	{
		std::cout << " ---------------------------------------Timed out -----------------------" << std::endl;
		return true;
	}
	if((fabs(m_heading) <  fabs(Robot::drivePID->GetYaw()))){

		std::cout << " heading is greater than 0" << std::endl;
		return true;
	}
	else{
			return false;
	}
////	if (Robot::drivePID->GetLeftEncoder() > m_distance && RobotS::drivePID->GetRightEncoder() > m_distance){
////		return true;
////	}
//
   //return false;
}

// Called once after isFinished returns true
void AutoRotate::End() {
	Robot::drivePID->SetSidePower(0, 0, 0, false);
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void AutoRotate::Interrupted() {

}