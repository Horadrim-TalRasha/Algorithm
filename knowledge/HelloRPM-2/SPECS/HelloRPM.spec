%define _topdir	 	/home/masayoshi/HelloRPM-2
%define name		HelloRPM
%define release		2
%define version 	2.0
%define buildroot       %{_topdir}/%{name}-%{version}-root

BuildRoot:      	%{buildroot}
Summary: 		Customer RPM Package
License: 		GPL
Name: 			%{name}
Version: 		%{version}
Release: 		%{release}
Requires:               gcc >= 4.0
Source: 		%{name}-%{version}.tar.gz
Patch:                  %{name}-%{version}.patch
Prefix: 		/usr
Group: 			Development/Tools

%description
A Customer binary file named "HelloRPM".

%prep
%setup -q

%patch -p1

%build
gcc -o HelloRPM.bin main.c

%install
mkdir -p $RPM_BUILD_ROOT/home/masayoshi
install HelloRPM.bin $RPM_BUILD_ROOT/home/masayoshi/HelloRPM.bin

%files
#%defattr(-,root,root)
/home/masayoshi/HelloRPM.bin
