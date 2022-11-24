# TempleOS-efi
Efi integrations wholey inside TempleOS 
## Overview
Create a fully self contained boot integration for TempleOS inside EFI, where all tools and compilation is performed completely insdei TempleOS

## Initial tasks
* Adapt the UFI header files for HolyC
* Implement the ability to create .efi files inside TempleOS for code wrtting in HolyC
* Create examples if EFI integrations

## Project layout

|Project Location| Location inside TempleOs| Overview |
|---|---|---|
| / | /Efisource | Main directory to house all the sources toosl and utilies for the integration|
| /Headers | /Efisource/Headers | Adapted EFI headers and method Stubs, these files don't describe functions in TempleOS they describe functions in EFI | 
| /Samples | /Efisource/Samples | Numbered samples building up in complexity |
| /Bootloader | /Efisource/Bootloader | Source for the TempleOS efi Bootloader |
| /Kernal | /Efisource/Kernel | Source for the modified kernal for EFI integration |

## Contributing
All contribitions are welcome, either create a pull request of log an issues against the project in Github

The overall TempleOS community benefits more by having documented code so for every .HC file please also include a corrosponding .md file and a corrosponding .DD file.

## Related Projects
[templeos-uefi](https://git.checksum.fail/alec/templeos-uefi/src/branch/master/TOSBoot)<br/>
[ZealOS](https://github.com/Zeal-Operating-System/ZealOS)
[3Days](https://github.com/Slapparoo/3Days)
