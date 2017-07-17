// RobotBuilder Version: 2.0
//
// This file was generated by RobotBuilder. It contains sections of
// code that are automatically generated and assigned by robotbuilder.
// These sections will be updated in the future when you export to
// C++ from RobotBuilder. Do not put any code or make any change in
// the blocks indicating autogenerated code or it will be lost on an
// update. Deleting the comments indicating the section will prevent
// it from being updated in the future.


#include "DriveWithVision.h"

// BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=CONSTRUCTOR

DriveWithVision::DriveWithVision(): Command() {
        // Use requires() here to declare subsystem dependencies
    // eg. requires(Robot::chassis.get());
	Requires(Robot::drivePID.get());
    // BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=REQUIRES
    // END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=REQUIRES

    m_table = NetworkTable::GetTable("GRIP/aGoalContours");
}

    // END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=CONSTRUCTOR

// Called just before this Command runs the first time
void DriveWithVision::Initialize() {

}

// Called repeatedly when this Command is scheduled to run
void DriveWithVision::Execute() {
	std::vector<double> arr = m_table->GetNumberArray("area", llvm::ArrayRef<double>());
	std::vector<double> centerYs = m_table->GetNumberArray("centerY", llvm::ArrayRef<double>());
	std::vector<double> centerXs = m_table->GetNumberArray("centerX", llvm::ArrayRef<double>());
	std::vector<double> widths = m_table->GetNumberArray("width", llvm::ArrayRef<double>());
	std::vector<double> heights = m_table->GetNumberArray("height", llvm::ArrayRef<double>());

	if (centerXs.empty() == true){
		std::cout << "AAHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHH" << std::endl;
		Robot::drivePID->ArcadeDrive(0, 0, 0);

	}
	else {
		double turnWithVision = (((*centerXs.data()) - 160)/200);
		//double direction = ((*centerXs.data())-160)/20;
		std::cout << "Center X:" << *centerXs.data() << "  Turn: " << turnWithVision << std::endl;

		if((*centerXs.data() < 165) && (*centerXs.data() > 155)){
			std::cout << " ----------------------------- returned true ---------------" << std::endl;
		}
		else{

		Robot::drivePID->ArcadeDrive(0.6, turnWithVision, 0);
		}

	}

}

// Make this return true when this Command no longer needs to run execute()
bool DriveWithVision::IsFinished() {
	std::vector<double> centerXs = m_table->GetNumberArray("centerX", llvm::ArrayRef<double>());
	if((*centerXs.data() < 165) && (*centerXs.data() > 155)){
		std::cout << " ----------------------------- returned true ---------------" << std::endl;
			return true;
	}
	else{
		return false;
	}
}

// Called once after isFinished returns true
void DriveWithVision::End() {

}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void DriveWithVision::Interrupted() {

}
