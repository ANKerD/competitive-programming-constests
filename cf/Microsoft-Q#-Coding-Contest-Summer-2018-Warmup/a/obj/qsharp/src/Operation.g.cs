#pragma warning disable 1591
using System;
using Microsoft.Quantum.Primitive;
using Microsoft.Quantum.Simulation.Core;
using Microsoft.Quantum.MetaData.Attributes;

[assembly: OperationDeclaration("Solution", "Solve (q : Qubit, sign : Int) : ()", new string[] { }, "/home/bot/contests/cf/Microsoft-Q#-Coding-Contest-Summer-2018-Warmup/A/Operation.qs", 152L, 6L, 5L)]
#line hidden
namespace Solution
{
    public class Solve : Operation<(Qubit,Int64), QVoid>, ICallable
    {
        public Solve(IOperationFactory m) : base(m)
        {
        }

        public class In : QTuple<(Qubit,Int64)>, IApplyData
        {
            public In((Qubit,Int64) data) : base(data)
            {
            }

            System.Collections.Generic.IEnumerable<Qubit> IApplyData.Qubits
            {
                get
                {
                    yield return Data.Item1;
                }
            }
        }

        String ICallable.Name => "Solve";
        String ICallable.FullName => "Solution.Solve";
        public override Func<(Qubit,Int64), QVoid> Body => (__in) =>
        {
            var (q,sign) = __in;
            // your code here
            ;
#line hidden
            return QVoid.Instance;
        }

        ;
        public override void Init()
        {
        }

        public override IApplyData __dataIn((Qubit,Int64) data) => new In(data);
        public override IApplyData __dataOut(QVoid data) => data;
        public static System.Threading.Tasks.Task<QVoid> Run(IOperationFactory __m__, Qubit q, Int64 sign)
        {
            return __m__.Run<Solve, (Qubit,Int64), QVoid>((q, sign));
        }
    }
}