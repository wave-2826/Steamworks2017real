// RobotBuilder Version: 2.0
//
// This file was generated by RobotBuilder. It contains sections of
// code that are automatically generated and assigned by robotbuilder.
// These sections will be updated in the future when you export to
// C++ from RobotBuilder. Do not put any code or make any change in
// the blocks indicating autogenerated code or it will be lost on an
// update. Deleting the comments indicating the section will prevent
// it from being updated in the future.



#include "Blue_AutoGearAngle.h"
#include "SetShooterSpeed.h"
#include "Fire.h"
#include "WaveWait.h"
#include "GearEject.h"
#include "AutoDrive.h"
#include "ZeroYaw.h"
#include "GearUneject.h"
#include "ResetEncoders.h"
#include "AutoRotate.h"

// BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=CONSTRUCTOR

Blue_AutoGearAngle::Blue_AutoGearAngle() {
// END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=CONSTRUCTOR

	AddSequential(new ZeroYaw());
	AddSequential(new ResetEncoders());
	AddSequential(new AutoDrive(57, 0, .7));
	AddSequential(new WaveWait(.5));
	AddSequential(new ResetEncoders());
	AddSequential(new ZeroYaw());
	AddSequential(new AutoRotate(17, 1, 1));
	AddSequential(new WaveWait(.5));
	AddSequential(new ZeroYaw());
	//AddSequential(new AutoDrive(56, -75, .7));
	AddSequential(new ResetEncoders());
	AddSequential(new ResetEncoders());
	AddSequential(new WaveWait(.5));
	AddSequential(new AutoDrive(18, 0, 1));
	AddSequential(new WaveWait(.5));
	AddSequential(new GearEject());
	AddSequential(new WaveWait(.5));
	AddSequential(new ResetEncoders());
	AddSequential(new ZeroYaw());

	AddSequential(new AutoDrive(-8, 0, -.7));
	AddSequential(new GearUneject());


     // Add Commands here:
    // e.g. AddSequential(new Command1());
    //      AddSequential(new Command2());
    // these will run in order.

    // To run multiple commands at the same time,
    // use AddParallel()
    // e.g. AddParallel(new Command1());
    //      AddSequential(new Command2());
    // Command1 and Command2 will run in parallel.

    // A command group will require all of the subsystems that each member
    // would require.
    // e.g. if Command1 requires chassis, and Command2 requires arm,
    // a CommandGroup containing them would require both the chassis and the
    // arm.
              // BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=COMMAND_DECLARATIONS
                      // END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=COMMAND_DECLARATIONS
 }
