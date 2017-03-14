// RobotBuilder Version: 2.0
//
// This file was generated by RobotBuilder. It contains sections of
// code that are automatically generated and assigned by robotbuilder.
// These sections will be updated in the future when you export to
// C++ from RobotBuilder. Do not put any code or make any change in
// the blocks indicating autogenerated code or it will be lost on an
// update. Deleting the comments indicating the section will prevent
// it from being updated in the future.


#ifndef _ROBOT_H
#define _ROBOT_H

#include "WPILib.h"
#include "Commands/Command.h"
#include "RobotMap.h"
#include "LiveWindow/LiveWindow.h"
#include "AHRS.h"

// BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=INCLUDES
#include "Commands/AutonomousCommand.h"
#include "Subsystems/Climb.h"
#include "Subsystems/CompressorSubsystem.h"
#include "Subsystems/Drive.h"
#include "Subsystems/Gear.h"
#include "Subsystems/Intake.h"
#include "Subsystems/Shooter.h"


    // END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=INCLUDES
#include "OI.h"
#include "Subsystems/DrivePID.h"

class Robot : public IterativeRobot {
public:
	std::unique_ptr<Command> autonomousCommand;
	static std::unique_ptr<OI> oi;
	LiveWindow *lw = LiveWindow::GetInstance();
//	SendableChooser *m_autoMode;

	// BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=DECLARATIONS
    static std::shared_ptr<Intake> intake;
//    static std::shared_ptr<Drive> drive;
    static std::shared_ptr<Gear> gear;
    static std::shared_ptr<Climb> climb;
    static std::shared_ptr<CompressorSubsystem> compressorSubsystem;
    static std::shared_ptr<Shooter> shooter;


    // END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=DECLARATIONS

    static std::shared_ptr<DrivePID> drivePID;
//    static std::shared_ptr<AHRS>m_gyro;


	virtual void RobotInit();
	virtual void DisabledInit();
	virtual void DisabledPeriodic();
	virtual void AutonomousInit();
	virtual void AutonomousPeriodic();
	virtual void TeleopInit();
	virtual void TeleopPeriodic();
	virtual void TestPeriodic();


private:

//	SendableChooser *m_alliance;
	//::unique_ptr<SendableChooser> m_autoMode;

	//SendableChooser <Command> *m_autoMode;

	// Used to start, increment, decrement, and stop the shooter motor
	bool m_incrementPressed;
	bool m_decrementPressed;
	bool m_stopPressed;
	int m_rpmSet;
	SendableChooser<Command*> *m_autoMode;

	AHRS *m_gyro;
};
#endif
