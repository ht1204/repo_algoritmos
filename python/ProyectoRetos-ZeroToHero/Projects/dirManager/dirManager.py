##Definición de librerías
import os, pathlib, shutil
"""
Clase FileEntity representa la carpeta donde se hallan los archivos a manipular, la ruta de estos se configura en el método
FileEntity.getSrcFileDir();

Clase FolderEntity representa las carpetas a crear con base en las extensiones de los archivos, la ruta a configurar se halla en el
método FolderEntity.getTargetFileDir(), en caso que al menos un archivo no posea extensión, se crea la carpeta 'noExt'.

Se utilizan rutas relativas, estas deben configurarse con base el directorio local donde se ejecute este Python script.
Versión de Python utilizada: 3.8
Debe ser ejecutado en entorno local, no en la nube.


Pautas de POO:
##Niveles de privacidad:
##Atributos:
## Público: self.name = name 
## Privado: self.__name = name  #Doble guión bajo
## Protected: self._name = name #Un guión bajo

##Métodos:
## Público: def foo(self): 
## Privado: def __foo(self):  #Doble guión bajo
## Protected: def _foo(self): #Un guión bajo

Buscar la mayor modularización y encapsulación en las operaciones posibles.
No crear clases sobre cargadas, sino como 'pequeñas cajas especializadas'. Ver principios como SOLID.
Evaluar todos los casos posibles.
Codificar pensando en los demás, lo más claro posible.

"""
### Start: Clase FileEntity
##  Objetivo: hallar archivos en directorio local e identificar sus extensiones.
class FileEntity:

    def __init__(self):
        pass

    def getSrcFileDir(self):
        return 'filesFolder'

    def getAllFiles(self):
        return os.listdir(self.getSrcFileDir())

    #Mostrar archivos en existencia.
    def inStockFilesList(self):
        print('Lista de archivos')
        for i in range(len(self.getAllFiles())):
            print(str(i + 1) + ' - ' + self.getAllFiles()[i])

    ##Método para visualizar extensiones de los archivos.
    ##Puede utilizarse en pruebas e implementaciones futuras.
    def getAllFilesExtensions(self):
        extensionList = []
        for file in self.getAllFiles():
            extension = str(pathlib.Path(file).suffix)
            extension = extension.replace('.', '')
            extensionList.append(extension)
        return extensionList

############ End of class ##############

### Start: Clase FolderEntity
##  Objetivo: gestiona carpetas con relación a extensiones de archivos
class FolderEntity:

    def __init__(self):
        self.__folderExist = False
        pass

    def getTargetFileDir(self):
        return 'extensionsFolder'

    def __getNoExtFile(self):
        return '/noExt'

    def getSeparator(self):
        return '/'

    def getFolderExist(self):
        return self.__folderExist

    def getTargetFolderList(self):
        return os.listdir(self.getTargetFileDir())

    def existentFolderList(self):
        print('Listado de carpetas creadas')
        for i in range(len(self.getTargetFolderList())):
            print(str(i + 1) + ' - ' + self.getTargetFolderList()[i])


    def createExtFolders(self,fileEntity):
        folderDirName=''
        for folderToCreate in fileEntity.getAllFilesExtensions():

            ##Si el archivo no tiene extensión, crea una carpeta llamada noExt.
            ##Si el archivo tiene extensión, crea su carpeta correspondiente.

            if(folderToCreate == ''):
                folderDirName = self.getTargetFileDir() + self.__getNoExtFile()
            else:
                folderDirName = self.getTargetFileDir() + self.getSeparator() + folderToCreate

            #Si no existe la carpeta, la crea. Identifica las que están creadas.
            if not os.path.exists(folderDirName):
                os.mkdir(folderDirName)
                self.__folderExist = True
                print("Carpeta: ", folderDirName, " ha sido creada ")

############ End of class ##############

### Start: Clase DirOperator
##  Objetivo: gestión en relación a mover archivos.
class DirOperator:

    def __init__(self):
        self.__fileEnt = FileEntity()
        self.__folderEnt = FolderEntity()
        pass


    def fileSelectionMove(self, fileList):
        print('Seleccione archivo a no mover')
        for i in range(len(fileList)):
            print(str(i + 1) + ' - ' + fileList[i])


    def targetFolderMove(self, targetFolders):
        print('Seleccione carpeta a mover archivos')
        for i in range(len(targetFolders)):
            print(str(i + 1) + ' - ' + targetFolders[i])

    #Descarta los archivos que no se van a mover por parte del usuario.
    def deleteFileNotMove(self,index,fileList):
        del fileList[index-1]
        return fileList

    #Selecciona carpeta adonde se van a mover archivos
    def selectFolderToMove(self, index, targetFolder):
        return targetFolder[index-1]


    #Mueve archivos a directorio seleccionado.
    def moveFiles(self, fileListToMove, targetFolder):
        for fileToMove in fileListToMove:
            shutil.move(
                self.__fileEnt.getSrcFileDir()+self.__folderEnt.getSeparator()+fileToMove,
                self.__folderEnt.getTargetFileDir()+self.__folderEnt.getSeparator()+targetFolder
            )



############ End of class ##############

### Start: Clase Validator
##  Objetivo: Validar ingresos de datos de usuario.
class Validator:
    def __init__(self):
        pass

    ####  Function optionValidator ######
    def optionValidator(self, value):
        while (True):
            try:
                value = int(input('Ingrese selección : \t'))
            except ValueError:
                print('Por favor, ingrese selección')
            else:
                break

        return value

    ############# End of function ##################


    ####  Function selectionDirValidator ######
    def selectionDirValidator(self, value, lstOptions):

        while (True):
            while (True):
                try:
                    value = int(input('Ingrese selección : \t'))
                except ValueError:
                    print('Por favor, ingrese selección permitida ')
                else:
                    break

            if (value < 1 or value > len(lstOptions)):
                print('Selección no debe pasar de rango')
            else:
                break

        return value
    ############# End of function ##################

    #### Function filesIn ####
    def filesIn(self, allFiles):
        return len(allFiles) > 0

    ############# End of function ##################

############ End of class ##############


## Start: Clase OperativeUtilities
## Objetivo: Funcionalidades a escoger en Clase Menú.
class OperativeUtilities:

    def __init__(self):
        self.__optionValidator = Validator()
        self.__dirOperatorEnt = DirOperator()



    def listFiles(self,fileEntObj):
        fileEntObj.inStockFilesList()

    def createFolders(self,folderEntObj,fileEntObj):
        folderEntObj.createExtFolders(fileEntObj)
        print('Creación de nuevas carpetas completada')


    def listExistentFolders(self,folderEntObj):
        folderEntObj.existentFolderList()


    def moveFiles(self,folderEntObj,fileEntObj):
        selectNoMove = 0
        selectTargetFolder = 0
        keepNoMove = ''

        # Copia de la lista de archivos original.
        # Facilita criterio de archivos a mover.
        fileList = list(fileEntObj.getAllFiles())
        while (keepNoMove != 'n' and len(fileList) > 0):
            self.__dirOperatorEnt.fileSelectionMove(fileList)
            selectNoMove = self.__optionValidator.selectionDirValidator(selectNoMove, fileList)
            fileList = self.__dirOperatorEnt.deleteFileNotMove(selectNoMove, fileList)
            keepNoMove = input("Presione 'n' para dejar de seleccionar ")

        if (len(fileList) > 0):

            print('Seleccione carpeta a mover los archivos')
            folderEntObj.existentFolderList()

            selectTargetFolder = self.__optionValidator.selectionDirValidator(
                selectTargetFolder, folderEntObj.getTargetFolderList()
            )

            folderToMove = self.__dirOperatorEnt.selectFolderToMove(selectTargetFolder,
                                                                    folderEntObj.getTargetFolderList()
                                                                    )
            self.__dirOperatorEnt.moveFiles(fileList, folderToMove)

            print('Archivos a mover')
            for i in range(len(fileList)):
                print(str(i + 1) + '- ' + fileList[i])

            print('Archivos movidos carpeta seleccionada :' +
                  folderEntObj.getTargetFileDir() + folderEntObj.getSeparator() + folderToMove
                  )
        else:
            print('No puede realizar operación')


############ End of class ##############


## Start: Clase Menu
## Objetivo: Menú de consola.
class Menu:

    def __init__(self):
        self.__optionValidator = Validator()
        self.__fileEnt = FileEntity()
        self.__folderEnt = FolderEntity()
        self.__dirOperatorEnt = DirOperator()
        self.__operativeUtil=OperativeUtilities()



    def optionsMenu(self):
        option=0
        value=''

        while(True):
            print('Menú')
            print('1- Listar archivos ')
            print('2- Crear Carpetas ')
            print('3- Listar Carpetas ')
            print('4- Mover archivos ')
            print('5- Salir')
            option=self.__optionValidator.optionValidator(value)

            if(option < 1 or option > 5):
                print('Selección incorrecta')
            elif(option == 1):

                ##Si no hay archivos, no los lista.
                if (self.__optionValidator.filesIn(self.__fileEnt.getAllFiles())):
                    self.__operativeUtil.listFiles(self.__fileEnt)
                else:
                    print('No hay archivos en existencias.')

            elif(option == 2):

                ##Si no hay archivos, no crea carpetas.
                if (self.__optionValidator.filesIn(self.__fileEnt.getAllFiles())):

                    ##Si existen carpetas, no vuelve a crear.
                    if(not self.__folderEnt.getFolderExist()):
                        self.__operativeUtil.createFolders(self.__folderEnt,self.__fileEnt)
                    else:
                        print('Archivos ya han sido creados. ')
                else:
                    print('No hay archivos en existencias.  ')

            elif(option == 3):

                if (self.__optionValidator.filesIn(self.__fileEnt.getAllFiles())):
                   self.__operativeUtil.listExistentFolders(self.__folderEnt)
                else:
                    print('No hay archivos en existencias.')

            elif(option == 4):

                if (self.__optionValidator.filesIn(self.__fileEnt.getAllFiles())):

                    self.__operativeUtil.moveFiles(self.__folderEnt, self.__fileEnt)

                else:
                    print('No hay archivos en existencias.')

            elif(option == 5):
                break
            print()
            print()
############ End of class ##############

##Instancia objeto menú
##Ejecución menú del sistema.
menu = Menu()
menu.optionsMenu()
