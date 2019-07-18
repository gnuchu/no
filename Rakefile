require 'os'
require 'bundler'

Bundler.require

def getcommand(command)
  if OS.windows?
    cmd = "powershell -noprofile -command \"& {(get-command #{command}).source}\""
  else
    cmd="which #{comand}"
  end

  `#{cmd}`.chop
end

PERL=getcommand('perl')
GCC=getcommand('gcc')
RM=OS.windows? ? 'del /q/s' : 'rm -rf'
$debug=false


def build
  puts "Using perl at #{PERL}"
  puts "Using gcc at #{GCC}"

  version
  clean
  compile
  link
end

def version
  cmd = "#{PERL} ./version_bumper.pl no.c"
  runCmd(cmd)
end

def clean
  cmd = "#{RM} *.o no no.exe"
  runCmd(cmd)
end

def compile
  cmd = "#{GCC} -c no.c"
  runCmd(cmd)
end

def link
  cmd = "#{GCC} -o no no.o"
  runCmd(cmd)

  cmd = "#{RM} *.o"
  runCmd(cmd)

  if !OS.windows?
    runCmd("chmod +x ./no")
  end
end

def runCmd(cmd)
  if $debug
    puts "About to run command: #{cmd}"
  end

  system("#{cmd}")

  if $debug
    puts "Command completed with status: #{$@}"
  end
  
end

task default: %w[all]

task :test do
  puts "Hello, World!"
end

task :all do
  build
end

task :debug do 
  $debug=true
  puts "Running in debug mode: #{$debug.to_s}"
  build
end
