# EditorToolbarBP

An Unreal Engine 4 plugin featuring editor toolbar buttons which call customizable Blueprint functions.

*If you enjoy this plugin and want to see it improve, please consider helping me buy some caffeine. *Or [hire me.](mailto:brian@superhockeyball.com)*<br>
[**Donate via PayPal**](https://paypal.me/bhicks85)*

#### What this is:
+ ...some uniquely customizable Blueprint functions which can be easily called from the editor toolbar.
+ ...a useful tool to simplify running project scripts and blutilities.
+ ...a way to improve your development workflow.

#### What this isn't:
+ ...an extension of engine functionality.
+ ...useful for gameplay. At all. Seriously, this just helps simplify tasks during development.
+ ...a profitable use of my time.

## Updates
*6/2/21* - Initial commit. It works, but it isn't pretty.

## Requirements
* **Supported Unreal Engine Versions** - 4.26 *(probably works in most engine versions, but has not been tested)*
* **Platforms** - UE4-Editor Only

## Installation
1) Place the `EditorToolbarBP` folder in `Engine\Plugins\Marketplace` or your project's `Plugins` folder
2) Regenerate project files
3) Compile engine
4) Enable the `EditorToolbarBP` plugin in your project
5) Create a new `EditorToolbarBP` actor and place it in your persistent level
6) Add the `Editor Toolbar Action` events and script functionality for them<br>
7) Press the buttons on the toolbar to see the results!

## FAQ / Common Issues
> #### So, what should I use this plugin for?<br>
Whatever you want! As an example, in a project which made heavy use of sequencer (and required each sequence to keep state upon completion) actors were frequently out of position while making editor adjustments. A quick script later and they're all always in the correct spot, with just the push of a button! You're limited only by your imagination (and the scope of blueprint functionality).
> #### Can the toolbar buttons or action events be renamed?<br>
Not yet, but that's coming soon!
> #### Why do I need the actor?<br>
Convenience! The actor is just an easy way to add blueprint implementable events.
> #### Does the actor get packaged with my game?<br>
Nope! The actor defaults to `Editor Only` and the plugin does not package with any projects. It's simply an editor tool.

## Support
For technical support, questions, comments, etc, please reach out on our [Discord Server](https://discord.gg/k6KxJvq).<br>
Find out more about InnerLoop LLC at [https://www.innerloopllc.com](https://www.innerloopllc.com).

## Legal
*EditorToolbarBP Plugin* by [ItsNotMeTrustMe *(Brian Edward Hicks)*](mailto:brian@superhockeyball.com) of InnerLoop LLC, 2021<br>
This plugin was not created by, or in partnership with, Epic Games or their partners/subsidiaries.<br>
No guarantees are made about anything. Use at your own risk. But please let me know if something breaks, so I can fix it.<br>
Please drink responsibly.
