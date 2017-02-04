// RobotBuilder Version: 2.0
//
// This file was generated by RobotBuilder. It contains sections of
// code that are automatically generated and assigned by robotbuilder.
// These sections will be updated in the future when you export to
// C++ from RobotBuilder. Do not put any code or make any change in
// the blocks indicating autogenerated code or it will be lost on an
// update. Deleting the comments indicating the section will prevent
// it from being updated in the future.


#include "Robot.h"

// BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=INITIALIZATION
std::shared_ptr<Intake> Robot::intake;
std::shared_ptr<Drive> Robot::drive;
std::shared_ptr<Gear> Robot::gear;
std::shared_ptr<Climb> Robot::climb;
std::shared_ptr<CompressorSubsystem> Robot::compressorSubsystem;
std::shared_ptr<Shooter> Robot::shooter;
std::unique_ptr<OI> Robot::oi;

    // END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=INITIALIZATION
std::shared_ptr<DrivePID> Robot::drivePID;
//std::shared_ptr<ShooterPID> Robot::shooterPID;
std::shared_ptr<ShooterPID> Robot::shooterPID;

void Robot::RobotInit() {
	RobotMap::init();
	// BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=CONSTRUCTORS
    intake.reset(new Intake());
    drive.reset(new Drive());
    gear.reset(new Gear());
    climb.reset(new Climb());
    compressorSubsystem.reset(new CompressorSubsystem());
    shooter.reset(new Shooter());

    // END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=CONSTRUCTORS
	// This MUST be here. If the OI creates Commands (which it very likely
	// will), constructing it during the construction of CommandBase (from
	// which commands extend), subsystems are not guaranteed to be
	// yet. Thus, their requires() statements may grab null pointers. Bad
	// news. Don't move it.
	oi.reset(new OI());
	drivePID.reset(new DrivePID());
	//shooterPID.reset(new ShooterPID());

	// instantiate the command used for the autonomous period
	// BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=AUTONOMOUS
	autonomousCommand.reset(new AutonomousCommand());

    // END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=AUTONOMOUS
	//ahrs = new AHRS(SerialPort::kMXP); // Alternatives:  SPI::kMXP, I2C::kMXP or SerialPort::kUSB
  }

/**
 * This function is called when the disabled button is hit.
 * You can use it to reset subsystems before shutting down.
 */
void Robot::DisabledInit(){
	compressorSubsystem->StopCompressor();
}

void Robot::DisabledPeriodic() {
	Scheduler::GetInstance()->Run();
	shooter->PrintShooterRPM();
}

void Robot::AutonomousInit() {
	if (autonomousCommand.get() != nullptr)
		autonomousCommand->Start();
}

void Robot::AutonomousPeriodic() {
	Scheduler::GetInstance()->Run();
}

void Robot::TeleopInit() {
	// This makes sure that the autonomous stops running when
	// teleop starts running. If you want the autonomous to
	// continue until interrupted by another command, remove
	// these lines or comment it out.
	if (autonomousCommand.get() != nullptr)
		autonomousCommand->Cancel();

	//compressorSubsystem->StartCompressor();

	m_incrementPressed = false;
	m_decrementPressed = false;
	m_stopPressed = false;
	m_rpmSet = 0;
}

void Robot::TeleopPeriodic() {
	Scheduler::GetInstance()->Run();

	//RobotMap::shooterShooterRight->Reset();
	//double rpmTest = oi->getOperatorJoystick()->GetRawAxis(0); //l/r on right axis
	shooter->SetShooterSpeed(600);
	shooter->UpdateSecondary();
	//RobotMap::shooterShooterRight->Set(RobotMap::shooterShooterRight->GetSetpoint());//commented out this line and then robot code DIED @enable

	//RobotMap::shooterShooterRight->Set(2);
	//RobotMap::shooterShooterLeft->Set(2);

	//shooter->PrintShooterRPM();

	//std::cout << "Fuel Detector:" << intake->IsFuelDetectorTripped() << std::endl;


	double move = oi->getDriverJoystick()->GetRawAxis(1);
	double 	turn = oi.get()->getDriverJoystick()->GetRawAxis(2);
	double roll = oi.get()->getDriverJoystick()->GetRawAxis(0);
	drive->SetSidePower(move, turn, 0);

	if(roll<0.2){
		RobotMap::driveHLeft->Set(roll);
		RobotMap::driveHRight->Set(-roll);
	}
	else if(roll>.2){
		RobotMap::driveHLeft->Set(roll);
		RobotMap::driveHRight->Set(-roll);
	}
	else{
		RobotMap::driveHLeft->Set(0);
		RobotMap::driveHRight->Set(0);
	}


	//Set shooter RPM

//	if(oi->getOperatorJoystick()->GetRawButton(2)){
//		shooter->SetShooterSpeed(200);
//	}
//	else{
//		shooter->SetShooterSpeed(0);
//	}
//	if(oi->getOperatorJoystick()->GetRawButton(2)) { //'B'
//		m_incrementPressed = true;
//	}
//	if(oi->getOperatorJoystick()->GetRawButton(1)) { //'A'
//		m_decrementPressed = true;
//	}
//	if(oi->getOperatorJoystick()->GetRawButton(8)) { //'Start'
//		m_stopPressed = true;
//	}
//
//	int changeValue = 50;
//	if(!(oi->getOperatorJoystick()->GetRawButton(2)) && m_incrementPressed) {
//		if(0 == m_rpmSet) { //motor isn't running yet
//			m_rpmSet = 200;
//		}
//		else
//		{
//			m_rpmSet += changeValue;
//		}
//		shooter->SetShooterSpeed(m_rpmSet);
//	}
//	if(!(oi->getOperatorJoystick()->GetRawButton(1)) && m_decrementPressed) {
//		if(m_rpmSet < changeValue) { //don't reverse the motor
//			m_rpmSet = 0;
//		}
//		else
//		{
//			m_rpmSet -= changeValue;
//		}
//		shooter->SetShooterSpeed(m_rpmSet);
//	}
//	if(!(oi->getOperatorJoystick()->GetRawButton(8)) && m_stopPressed) {
//		m_rpmSet = 0;
//
//	}
	//shooter->SetShooterSpeed(m_rpmSet);
	shooter->PrintShooterRPM();

	Wait(0.005); //seconds
}

void Robot::TestPeriodic() {
	lw->Run();

	std::cout<<"ClimbDetectorForward : "<<RobotMap::climbClimbDetectorForward<<std::endl;

	std::cout<<"ClimbDetectorBack :"<<RobotMap::climbClimbDetectorBack<<std::endl;

	std::cout<<"FuelDetector :"<<RobotMap::intakeFuelDetector<<std::endl;
}

START_ROBOT_CLASS(Robot);


