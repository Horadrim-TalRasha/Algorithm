%define _topdir	 	/home/masayoshi/HelloRPM
%define name		HelloRPM
%define release		1
%define version 	1.12
%define buildroot       %{_topdir}/%{name}-%{version}-root

BuildRoot:      	%{buildroot}
Summary: 		Customer RPM Package
License: 		GPL
Name: 			%{name}
Version: 		%{version}
Release: 		%{release}
Source: 		%{name}-%{version}.tar.gz
Prefix: 		/usr
Group: 			Development/Tools

%description
A Customer binary file named "HelloRPM".

%prep
%setup -q

%build
gcc -o HelloRPM.bin main.c

%install
mkdir -p $RPM_BUILD_ROOT/home/masayoshi
install HelloRPM.bin $RPM_BUILD_ROOT/home/masayoshi/HelloRPM.bin

%files
#%defattr(-,root,root)
/home/masayoshi/HelloRPM.bin
